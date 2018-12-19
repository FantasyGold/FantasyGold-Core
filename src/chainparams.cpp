// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// // Copyright (c) 2015-2017 The Bulwark developers
// Copyright (c) 2017-2018 The FantasyGold developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
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
    boost::assign::map_list_of(750, uint256("0x0000000004526e78914301cb0a008801a9219ed07c659860404bfafc6f983701"));
static const Checkpoints::CCheckpointData dataMainNet = {
    &mapCheckpoints,
    1525119213,// * UNIX timestamp of last checkpoint block
    750,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    10        // * estimated number of transactions per day after checkpoint
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

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x54;
        pchMessageStart[1] = 0x49;
        pchMessageStart[2] = 0x4D;
        pchMessageStart[3] = 0x42;

		vAlertPubKey = ParseHex("048a8a673e322e02cae3b27a95b93551abb29772906923641d572e2e9dc5e3c2707ec37122a16d5563e883b673eec7f6e5894c54e281a5f18518b0f173471229ad");
        nDefaultPort = 57810;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // FantasyGold starting difficulty is 1 / 2^12
        nMaxReorganizationDepth = 100;
        nMinerThreads = 0;
        nTargetTimespan = 90; // FantasyGold: 1.5 minutes
        nTargetSpacing = 90;  // FantasyGold: 6 Minutes
        nLastPOWBlock = 43200;
        nMaturity = 66;
        nModifierUpdateBlock = 1;
		nMaxMoneyOut = 21000000 * COIN;
       	nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
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
		vSeeds.push_back(CDNSSeedData("seed-england-london.fantasygold.network", "seed-england-london.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-eu-frankfurt.fantasygold.network", "seed-eu-frankfurt.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-eu-ireland.fantasygold.network", "seed-eu-ireland.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-eu-london.fantasygold.network", "seed-eu-london.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-eu-paris.fantasygold.network", "seed-eu-paris.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-south-america-saopaulo.fantasygold.network", "seed-south-america-saopaulo.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-1.fantasygold.network", "seed-us-1.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-2.fantasygold.network", "seed-us-2.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-3.fantasygold.network", "seed-us-3.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-4.fantasygold.network", "seed-us-4.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-5.fantasygold.network", "seed-us-5.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-6.fantasygold.network", "seed-us-67.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-7.fantasygold.network", "seed-us-7.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-central-dallas.fantasygold.network", "seed-us-central-dallas.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-east-atlanta.fantasygold.network", "seed-us-east-atlanta.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-east-newark.fantasygold.network", "seed-us-east-newark.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-us-west-fremont.fantasygold.network", "seed-us-west-fremont.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-asia-mumbai.fantasygold.network", "seed-asia-mumbai.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-asia-singapore.fantasygold.network", "seed-asia-singapore.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-asia-seoul.fantasygold.network", "seed-asia-seoul.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-asia-tokyo.fantasygold.network", "seed-asia-tokyo.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-australia-sydney.fantasygold.network", "seed-australia-sydney.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-canada-central.fantasygold.network", "seed-canada-central.fantasygold.network"));
		vSeeds.push_back(CDNSSeedData("seed-denmark-frankfurt.fantasygold.network", "seed-denmark-frankfurt.fantasygold.network"));
				
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
        strSporkKey = "04d8bc8901ec5b46c8e23d94a4ed2d69d127c4aa79311a28058bb6ab3c87505cefbb4ff9161c285dcf34cf846d2c4eda945d5331902195f8a064bdf6053d0d6767";
        strObfuscationPoolDummyAddress = "fDiJwVuKv9dcKBN4KCfX6UmXbkpqLfzGyf";
        nStartMasternodePayments = 1511092620; //November 19, 2017 11:57:00 AM 

        /** Zerocoin */
        zerocoinModulus = "b2275261dcaa303374af30576c5f676c8c2f1596aae7814f932f08839d442a5b2f7eaac75ffe9481321cbaae1c48703eff"
            "384222885cf9e07e3996fa36d25f0866a7f3834c2457b253b0bbbd0ec23036fcc6c84886cce4d6bcc917ce7fb40d3ffcc12984db02e55e4e"
            "ccd205f7a239fe48ab27ea1124efa0a545ae434876b0b934ebcc54b03375c78bdbb1cde74c8e42048839e191f3986436f757c11d36b60942"
            "f6b88f40acbcd4b36d82890e05b6e508192873dee5be51352e7215fbca7dfe30daac0efd8435426313557b1d193be3fa3be8c3c81f5501e0"
            "52478afcfc1bd1f06ff429ecae3b682faa26bda5bb530fe1eca4d630fadc3b5d15e3d1feeeb161812894d3f17f497bb321c224f5419e30d2"
            "b79511979fa41d24bc78c0aa18e12dc668b164841ce56bc8de5b7386cff2bb314b11094a4ad5661a7fd7b517181f8a999e61ddadc6936262"
            "80b2692bc5b62bd328eb0b4c7d48b98942b0e6037add6568897f41adb825482057ae6224531047eef0cfd8f5510eb64e0610d83a1c7181";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee

        /** Staking Requirements */
        nStakeMinStartProtocol = 70850; // Starting protocol version (ActiveProtocol())
        nStakeMinConfirmations = 475; // Required number of confirmations
        nStakeMinAmount = 100 * COIN; // Minimum required staking amount
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
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

		vAlertPubKey = ParseHex("04a1c011a5c59b09f6ac5ca2acaa1827c3c9dde95e01c1383c2159d2f769ef97d7a14526c7c0bae6391d66baa16bdbb255679811f30c42e377f364ad202c3461dd");
        nDefaultPort = 58806;
        nMinerThreads = 0;
        nTargetTimespan = 90; // 90 Seconds
        nTargetSpacing = 90;  // 360 Seconds
        nLastPOWBlock = 800;
        nMaturity = 15;
		nMaxMoneyOut = 21000000 * COIN;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT

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
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04d45e7b9bd690618bbf1275990c42db1d15f6c059bdafcd0362f30e64e134fdfdbbbe17e0ad4d6cd17c5d8eae7163cbaf8518b8c45039062c8283c1bc4de67890";
        strObfuscationPoolDummyAddress = "FQfdVa57fUXHEU7zboSbyGeBkS63gpowW3";
        nStartMasternodePayments = 1511092620; //November 19, 2017 11:57:00 AM
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet

        /** Staking Requirements */
        nStakeMinStartProtocol = 70850; // Starting protocol version (ActiveProtocol())
        nStakeMinConfirmations = 30; // Required number of confirmations
        nStakeMinAmount = 500 * COIN; // Minimum required staking amount
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
        nDefaultPort = 60806;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
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
