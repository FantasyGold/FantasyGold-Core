// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// // Copyright (c) 2015-2017 The Bulwark developers
// Copyright (c) 2017-2018 The FantasyGold developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"
#include <assert.h>
#include <boost/assign/list_of.hpp>
using namespace std;
using namespace boost::assign;
struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};
#include "chainparamsseeds.h"
/**
 * Main network
 */

void MineGenesis(CBlock genesis){
    // This will figure out a valid hash and Nonce if you're creating a different genesis block:
    uint256 newhash = genesis.GetHash();
    uint256 besthash;
    int64_t nStart = GetTime();
    uint256 hashTarget = ~uint256(0) >> 20;
    printf("Target: %s\n", hashTarget.GetHex().c_str());
    memset(&besthash,0xFF,32);
    while (newhash > hashTarget) {
        ++genesis.nNonce;
        if (genesis.nNonce == 0){
            printf("NONCE WRAPPED, incrementing time");
            ++genesis.nTime;
        }
        newhash = genesis.GetHash();
        if(newhash < besthash){
            besthash=newhash;
            printf("New best: %s\n", newhash.GetHex().c_str());
        }
    }
    printf("Found Genesis, Nonce: %ld, Hash: %s\n", genesis.nNonce, genesis.GetHash().GetHex().c_str());
    printf("Gensis Hash Merkle: %s\n", genesis.hashMerkleRoot.ToString().c_str());
}
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}
//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of(0, uint256(""));
static const Checkpoints::CCheckpointData dataMainNet = {
    &mapCheckpoints,
    1509922046,// * UNIX timestamp of last checkpoint block
    0,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1509884281,
    0,
    250};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};
class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce a large 4-byte int at any alignment.
         * a large 4-byte int at any alignment. here
         */
        pchMessageStart[0] = 0x54;
        pchMessageStart[1] = 0x49;
        pchMessageStart[2] = 0x4D;
        pchMessageStart[3] = 0x42;

		vAlertPubKey = ParseHex("04d16502d4e8269b2231cf6835302862c537e7c82c4514f0ee070c8649df663dbb3e19b2e24722cbb0e4c624330a4a4df404a43614487a0a8dca26cfe78dbdcd65");
        nDefaultPort = 57806;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // FantasyGold starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 210000;
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 90; // FantasyGold: 1.5 minutes
        nTargetSpacing = 90;  // FantasyGold: 6 Minutes
        nLastPOWBlock = 500;
        nMaturity = 66;
        nModifierUpdateBlock = 1;
		nMaxMoneyOut = 21000000 * COIN;
        const char* pszTimestamp = "FORBES AUG 20 2013 The $70 Billion Fantasy Football Market";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 25 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04243e8da79e117dba99d89a2da6ed761af43175227d19caaffea72398514962af9701478a69410b8158e190ae36d50a1f7325eba3df9559ad345db0cb72bfe2e2") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1509922046;
        genesis.nBits = bnProofOfWorkLimit.GetCompact();;
        genesis.nNonce = 1015505; 
		//MineGenesis(genesis);
		hashGenesisBlock = genesis.GetHash();

		assert(hashGenesisBlock == uint256("0x000006b85859195cd62b57d137bba5871588d8f05cecc5fa21673e4c894e8997"));
	    assert(genesis.hashMerkleRoot == uint256("0x57efb4ec57bf3c7424a679cc41bec99026d6e6b90a91f26cda0b8d5249559502"));


		vSeeds.clear();
		vFixedSeeds.clear();
        vSeeds.push_back(CDNSSeedData("ec2-18-219-73-66.us-east-2.compute.amazonaws.com", "ec2-18-219-73-66.us-east-2.compute.amazonaws.com"));
    	vSeeds.push_back(CDNSSeedData("ec2-18-188-129-68.us-east-2.compute.amazonaws.com", "ec2-18-188-129-68.us-east-2.compute.amazonaws.com"));
	//	vSeeds.push_back(CDNSSeedData("fantasygoldcrypto.com", "seed-06-newark-nj.fantasygoldcrypto.com"));
    //	vSeeds.push_back(CDNSSeedData("fantasygoldcrypto.com", "seed04.fantasygoldcrypto.com"));
		
		
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 35); // f
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 18); 
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x46)(0x53)(0x47)(0x4D).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x66)(0x73)(0x67)(0x70).convert_to_container<std::vector<unsigned char> >();
        //  BIP44 coin type is 'TBD'
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x13)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;
        nPoolMaxTransactions = 3;
		strSporkKey = "04f797a49391edf1488c226700a96fa93d225a3645a57edc3f66fa402cedb34bd6853635c98c72dfbc3eb5b2eb230a06e3c4f6ef008b71e28b1d815a4606b077c3";
        //FIXME
        strObfuscationPoolDummyAddress = "fDiJwVuKv9dcKBN4KCfX6UmXbkpqLfzGyf";
        nStartMasternodePayments = 1511092620; //Wed, 25 Jun 2014 20:36:16 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataMainNet;
    }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x41;
        pchMessageStart[1] = 0x02;
        pchMessageStart[2] = 0x35;
        pchMessageStart[3] = 0x64;

		vAlertPubKey = ParseHex("0493fb4b869faa6ce0e38a9808d0a8ca91d263ca236876cf34a44d7eca68cc771adc3566713412877ec146ce8736fc464967d9c4c2ba774d1855d0362861ec5825");
        nDefaultPort = 58806;
        nMinerThreads = 0;
        nTargetTimespan = 90; // 90 Seconds
        nTargetSpacing = 90;  // 360 Seconds
        nLastPOWBlock = 50;
        nMaturity = 15;
		nMaxMoneyOut = 21000000 * COIN;
        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1508638280;
        genesis.nNonce = 1081421;
		genesis.nBits = bnProofOfWorkLimit.GetCompact();
		//MineGenesis(genesis);
        hashGenesisBlock = genesis.GetHash();
		assert(hashGenesisBlock == uint256("0x000005b218ee50a90d18144376a07d8fa5e2477b234c1a7df54fa29229ecf96c"));
		assert(genesis.hashMerkleRoot == uint256("0x57efb4ec57bf3c7424a679cc41bec99026d6e6b90a91f26cda0b8d5249559502"));

        vFixedSeeds.clear();
        vSeeds.clear();
		//vSeeds.push_back(CDNSSeedData("fantasygoldcrypto.com", "test01.fantasygoldcrypto.com"));
		//vSeeds.push_back(CDNSSeedData("fantasygoldcrypto.com", "test02.fantasygoldcrypto.com"));
		//vSeeds.push_back(CDNSSeedData("fantasygoldcrypto.com", "test03.fantasygoldcrypto.com"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 65); // Testnet fantasygold addresses start with 'T'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 12);  // Testnet fantasygold script addresses start with '5' or '6'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet fantasygold BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet fantasygold BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet fantasygold BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container<std::vector<unsigned char> >();
        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
        fRequireRPCPassword = true;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;
        nPoolMaxTransactions = 2;
        strSporkKey = "043b3c416f009f4bbc8f414d4728259674f9d2db948a486b57034a8b9cce73f62a8b23b7eaee1f3e5f23faa5fbab6e0389007a2c35d4f00ab33531063b96dec1d1";
        strObfuscationPoolDummyAddress = "FQfdVa57fUXHEU7zboSbyGeBkS63gpowW3";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // FantasyGold: 1 day
        nTargetSpacing = 1 * 60;        // FantasyGold: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 3503480;
		//MineGenesis(genesis);
        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 59806;
    	assert(hashGenesisBlock == uint256("00000469c51791d203c00e59b9b1fde736b5f4c16c7e54ab1b87aefe3bd05a9c"));
        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.
        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return dataMainNet;
    }
    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;
static CChainParams* pCurrentParams = 0;
CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}
const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}
CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}
void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}
bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;
    SelectParams(network);
    return true;
}
