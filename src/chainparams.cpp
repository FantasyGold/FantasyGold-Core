// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
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
//void MineGenesisBlock(CBlock &genesis);
/**
 * Main network
 */
//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector < CAddress > & vSeedsOut,
    const SeedSpec6 * data, unsigned int count) {
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
      struct in6_addr ip;
      memcpy( & ip, data[i].addr, sizeof(ip));
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
  boost::assign::map_list_of(0, uint256("0x00000a29a4e72b27b41c203379bc549593f10760f7260daef1a87bf667854846"));

static
const Checkpoints::CCheckpointData data = { & mapCheckpoints,
  1522907468, // * UNIX timestamp of last checkpoint block
  0, // * total number of transactions between genesis and last checkpoint
  //   (the tx=... number in the SetBestChain debug.log lines)
  1 // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
  boost::assign::map_list_of(0, uint256("0x0000003d6339fe3edd382f6477a9f06d48e85cf3515565e6af669f94cf2fef98"));
static
const Checkpoints::CCheckpointData dataTestnet = { & mapCheckpointsTestnet,
  1522907634,
  0,
  250
};
static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
  boost::assign::map_list_of(0, uint256("0x001"));
static
const Checkpoints::CCheckpointData dataRegtest = { & mapCheckpointsRegtest,
  1454124731,
  0,
  100
};
class CMainParams: public CChainParams {
  public: CMainParams() {
    networkID = CBaseChainParams::MAIN;
    strNetworkID = "main";
    /**
     * The message start string is designed to be unlikely to occur in normal data.
     * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
     * a large 4-byte int at any alignment.
     */
    pchMessageStart[0] = 0x3d;
    pchMessageStart[1] = 0x07;
    pchMessageStart[2] = 0x18;
    pchMessageStart[3] = 0xa7;
    vAlertPubKey = ParseHex("0410d9c7db125d31412192b56ae3e9906bdd5e0f8c8d61d0f8ea3a3624c7547efcefa434861a0e26ca9124a2e09addda6d1dc0d91c5cb8425400c518740b659e20");
    nDefaultPort = 57806;
    bnProofOfWorkLimit = ~uint256(0) >> 20; // FantasyGold starting difficulty is 1 / 2^12
    nMaxReorganizationDepth = 100;
    nMinerThreads = 0;
    nTargetTimespan = 1 * 90; // FantasyGold: 1.5 minutes
    nTargetSpacingSlowLaunch = 5 * 90; // FantasyGold: 7.5 minutes (Slow launch - Block 300)
    nTargetSpacing = 1 * 90; // FantasyGold: 1.5min after block 300
    nLastPOWBlock = 345600; // 1 Year
    nRampToBlock = 960; // Slow start, ramp linearly to this block
    nMaturity = 66; // 99 Minutes
    nMasternodeCountDrift = 4;
    nModifierUpdateBlock = 1;
    nMaxMoneyOut = 21525720 * COIN; // Year 2

    nEnforceBlockUpgradeMajority = 750;
    nRejectBlockOutdatedMajority = 950;
    nToCheckBlockUpgradeMajority = 1000;
    //mine the genises block
    // CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
    //   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
    //     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
    //     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
    //   vMerkleTree: e0028e

    const char * pszTimestamp = "FORBES AUG 20 2013 The $70 Billion Fantasy Football Market";
    CMutableTransaction txNew;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector < unsigned char > ((const unsigned char * ) pszTimestamp, (const unsigned char * ) pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = 50 * COIN;
    txNew.vout[0].scriptPubKey = CScript() << ParseHex("043e368c2054898d58b24312d16ae360d605bf9e4ebba3575026a33264db4c7964643ac7477cecbb9d7078c3328c955f49930e233aee1e453680d728a88ba8155d") << OP_CHECKSIG;
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();
    genesis.nVersion = 1;
    genesis.nTime = 1522907468;
    genesis.nBits = bnProofOfWorkLimit.GetCompact();
    genesis.nNonce = 2765953;
    hashGenesisBlock = genesis.GetHash();
    MineGenesisBlock(genesis);
    assert(hashGenesisBlock == uint256("0x00000a29a4e72b27b41c203379bc549593f10760f7260daef1a87bf667854846"));
    assert(genesis.hashMerkleRoot == uint256("0x634fd30aee03a4da0402ec7255286c3bef6f239e4ba6c4a2c7154319f635cecc"));
    vSeeds.push_back(CDNSSeedData("ec2-18-221-160-231.us-east-2.compute.amazonaws.com", "ec2-18-221-160-231.us-east-2.compute.amazonaws.com"));
 
    base58Prefixes[PUBKEY_ADDRESS] = std::vector < unsigned char > (1, 35); // F
    base58Prefixes[SCRIPT_ADDRESS] = std::vector < unsigned char > (1, 18);
    base58Prefixes[SECRET_KEY] = std::vector < unsigned char > (1, 212);
    base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container < std::vector < unsigned char > > ();
    base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container < std::vector < unsigned char > > ();
    //  BIP44 as defined by https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki
    base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container < std::vector < unsigned char > > ();
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
    strSporkKey = "044a2d0562a232c16823d3be48d3ad6a69d2880fa7f8ad77001e90b5090d5fbeb805bc3a7bc48d9a4683490a63a84e245d7736b6791f92bf6c2747122ceaf6976e";
    strObfuscationPoolDummyAddress = "bDiJwVuKv9dcKBN4KCfX6UmXbkpqLfzGyf";
    nStartMasternodePayments = 1522972800;
  }
  const Checkpoints::CCheckpointData & Checkpoints() const {
    return data;
  }
};
static CMainParams mainParams;
/**
 * Testnet (v3)
 */
class CTestNetParams: public CMainParams {
  public: CTestNetParams() {
    networkID = CBaseChainParams::TESTNET;
    strNetworkID = "test";
    pchMessageStart[0] = 0xb5;
    pchMessageStart[1] = 0xd9;
    pchMessageStart[2] = 0xf4;
    pchMessageStart[3] = 0xa0;

    vAlertPubKey = ParseHex("0410b878184f4f0679d08c92d77edbd900c2d0b3af956c828a0df17dbfe63e6631331cc462ab8f5cef765c75d5d5790d11a93998d4ed97112c489c69e34595ee27");
    nDefaultPort = 42133;
    nMinerThreads = 0;
    nTargetTimespan = 1 * 90; // 90 Seconds
    nTargetSpacing = 1 * 90; // 90 Seconds
    nTargetSpacingSlowLaunch = 1 * 90; // Kludgy but don't want to check for testnet each time in GetNextWorkRequired
    nLastPOWBlock = 1000;
    nMaturity = 15;
    nMaxMoneyOut = 33284220 * COIN; // 2032 Maximum
    nEnforceBlockUpgradeMajority = 51;
    nRejectBlockOutdatedMajority = 75;
    nToCheckBlockUpgradeMajority = 100;

    //! Modify the testnet genesis block so the timestamp is valid for a later start.
    genesis.nTime = 1522907634;
    genesis.nNonce = 5463097;
    genesis.nBits = bnProofOfWorkLimit.GetCompact();
    hashGenesisBlock = genesis.GetHash();
    //MineGenesisBlock(genesis);
    assert(hashGenesisBlock == uint256("0x0000003d6339fe3edd382f6477a9f06d48e85cf3515565e6af669f94cf2fef98"));
    assert(genesis.hashMerkleRoot == uint256("0x634fd30aee03a4da0402ec7255286c3bef6f239e4ba6c4a2c7154319f635cecc"));

    vFixedSeeds.clear();
    vSeeds.clear();
    //vSeeds.push_back(CDNSSeedData("testnet01.mempool.pw", "testnet01.mempool.pw"));
    //vSeeds.push_back(CDNSSeedData("testnet02.mempool.pw", "testnet02.mempool.pw"));
    //vSeeds.push_back(CDNSSeedData("testnet03.mempool.pw", "testnet03.mempool.pw"));

    base58Prefixes[PUBKEY_ADDRESS] = std::vector < unsigned char > (1, 65); // Testnet fantasygold addresses start with 'T'
    base58Prefixes[SCRIPT_ADDRESS] = std::vector < unsigned char > (1, 12); // Testnet fantasygold script addresses start with '5' or '6'
    base58Prefixes[SECRET_KEY] = std::vector < unsigned char > (1, 239); // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
    // Testnet fantasygold BIP32 pubkeys start with 'DRKV'
    base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container < std::vector < unsigned char > > ();
    // Testnet fantasygold BIP32 prvkeys start with 'DRKP'
    base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container < std::vector < unsigned char > > ();
    // Testnet fantasygold BIP44 coin type is '1' (All coin's testnet default)
    base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x01)(0x00)(0x00)(0x80).convert_to_container < std::vector < unsigned char > > ();
    convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));
    fRequireRPCPassword = true;
    fMiningRequiresPeers = false;
    fAllowMinDifficultyBlocks = true;
    fDefaultConsistencyChecks = false;
    fRequireStandard = false;
    fMineBlocksOnDemand = false;
    fTestnetToBeDeprecatedFieldRPC = true;
    nPoolMaxTransactions = 2;
    strSporkKey = "046725fc2953ae8f325edb3b696dbbf8f2a0980e8dc9c79a5fc084fa0071d142360f9982fc619af0edd7386b9032d2a48ecd79d908625ce5073da2d8668603e7bf";
    strObfuscationPoolDummyAddress = "TUQ57Fbh1crybrDhV6X9SDH95H4oSq4v6p";
    nStartMasternodePayments = 1522972800; //Fri, 09 Jan 2015 21:05:58 GMT
  }
  const Checkpoints::CCheckpointData & Checkpoints() const {
    return dataTestnet;
  }
};
static CTestNetParams testNetParams;
/**
 * Regression test
 */
class CRegTestParams: public CTestNetParams {
  public: CRegTestParams() {
    networkID = CBaseChainParams::REGTEST;
    strNetworkID = "regtest";
    strNetworkID = "regtest";
    pchMessageStart[0] = 0xf3;
    pchMessageStart[1] = 0x6d;
    pchMessageStart[2] = 0xd7;
    pchMessageStart[3] = 0xc4;
    nMinerThreads = 1;
    nTargetTimespan = 24 * 60 * 60; // FantasyGold: 1 day
    nTargetSpacing = 1 * 60; // FantasyGold: 1 minutes
    bnProofOfWorkLimit = ~uint256(0) >> 1;
    genesis.nTime = 1454124731;
    genesis.nBits = 0x207fffff;
    genesis.nNonce = 12345;
    hashGenesisBlock = genesis.GetHash();
    nDefaultPort = 51476;
    //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));
    vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
    vSeeds.clear(); //! Testnet mode doesn't have any DNS seeds.
    fRequireRPCPassword = false;
    fMiningRequiresPeers = false;
    fAllowMinDifficultyBlocks = true;
    fDefaultConsistencyChecks = true;
    fRequireStandard = false;
    fMineBlocksOnDemand = true;
    fTestnetToBeDeprecatedFieldRPC = false;
  }
  const Checkpoints::CCheckpointData & Checkpoints() const {
    return dataRegtest;
  }
};
static CRegTestParams regTestParams;
/**
 * Unit test
 */
class CUnitTestParams: public CMainParams, public CModifiableParams {
  public: CUnitTestParams() {
    networkID = CBaseChainParams::UNITTEST;
    strNetworkID = "unittest";
    nDefaultPort = 51478;
    vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
    vSeeds.clear(); //! Unit test mode doesn't have any DNS seeds.
    fRequireRPCPassword = false;
    fMiningRequiresPeers = false;
    fDefaultConsistencyChecks = true;
    fAllowMinDifficultyBlocks = false;
    fMineBlocksOnDemand = true;
  }
  const Checkpoints::CCheckpointData & Checkpoints() const {
      // UnitTest share the same checkpoints as MAIN
      return data;
    }
    //! Published setters to allow changing values in unit test cases
  virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) {
    fDefaultConsistencyChecks = afDefaultConsistencyChecks;
  }
  virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) {
    fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks;
  }
  virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) {
    fSkipProofOfWorkCheck = afSkipProofOfWorkCheck;
  }
  virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) {
    nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority;
  }
  virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) {
    nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority;
  }
  virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) {
    nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority;
  }
};
static CUnitTestParams unitTestParams;
static CChainParams * pCurrentParams = 0;
CModifiableParams * ModifiableParams() {
  assert(pCurrentParams);
  assert(pCurrentParams == & unitTestParams);
  return (CModifiableParams * ) & unitTestParams;
}
const CChainParams & Params() {
  assert(pCurrentParams);
  return *pCurrentParams;
}
CChainParams & Params(CBaseChainParams::Network network) {
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
void SelectParams(CBaseChainParams::Network network) {
  SelectBaseParams(network);
  pCurrentParams = & Params(network);
}
bool SelectParamsFromCommandLine() {
  CBaseChainParams::Network network = NetworkIdFromCommandLine();
  if (network == CBaseChainParams::MAX_NETWORK_TYPES)
    return false;
  SelectParams(network);
  return true;
}

void MineGenesisBlock(CBlock &genesis)
{
    uint256 best = uint256();();
    int n=0;
    uint256 hashTarget = uint256().SetCompact(genesis.nBits);
    while (uint256(genesis.GetHash()) > hashTarget) {
      uint256 c=uint256(genesis.GetHash());
      if(c < best || n==0) {
        best = c;
        n=1;
        printf("%s %s %s\n",genesis.GetHash().GetHex().c_str(),hashTarget.GetHex().c_str(),
        best.GetHex().c_str());
      }
    ++genesis.nNonce;
    if (genesis.nNonce == 0) { ++genesis.nTime; }
  }    
printf("HASH IS: %s\n", uint256(genesis.GetHash()).ToString().c_str());
printf("Converting genesis hash to string: %s\n",genesis.ToString().c_str());
}