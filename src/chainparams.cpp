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
  boost::assign::map_list_of(0, uint256("0x00000000579133b6ce9f275d5dfa9bcda51fcb6969ecb110ca90900b9fd2c3c1"));

static
const Checkpoints::CCheckpointData data = { & mapCheckpoints,
  1522369905, // * UNIX timestamp of last checkpoint block
  0, // * total number of transactions between genesis and last checkpoint
  //   (the tx=... number in the SetBestChain debug.log lines)
  1 // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
  boost::assign::map_list_of(0, uint256("0x"));
static
const Checkpoints::CCheckpointData dataTestnet = { & mapCheckpointsTestnet,
  1514516171,
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
    vAlertPubKey = ParseHex("048413be78951696a003fe63b15622b523f96b3fbbac555058c98b9344b1d38d9b170bf3ec220e25114b17290282aa87af8077e8e6abca4a3f9748b924afb49c27");
    //https://pastebin.com/tZuCdC00 valertpubkeygenerator
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

    //
    const char * pszTimestamp = "Guardian Feb 8 2018 Encryption keeps us safe It must not be compromised with backdoors";
    CMutableTransaction txNew;
    txNew.vin.resize(1);
    txNew.vout.resize(1);
    txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector < unsigned char > ((const unsigned char * ) pszTimestamp, (const unsigned char * ) pszTimestamp + strlen(pszTimestamp));
    txNew.vout[0].nValue = 50 * COIN;
    txNew.vout[0].scriptPubKey = CScript() << ParseHex("04d1c7f140fc09cf4c77312683b4e72378f5d4beca85a2e7d517d6b1a1b6afed4dd7959155c788b50fe672c07606d1a407d14dadd481549c4ce29e2b540ba0ad20") << OP_CHECKSIG;
    //https://pastebin.com/tZuCdC00 scriptpubkey generator
    genesis.vtx.push_back(txNew);
    genesis.hashPrevBlock = 0;
    genesis.hashMerkleRoot = genesis.BuildMerkleTree();
    genesis.nVersion = 1;
    genesis.nTime = 1522814856;
    genesis.nBits = bnProofOfWorkLimit.GetCompact();;
    genesis.nNonce = 535769390;
    hashGenesisBlock = genesis.GetHash();
    
    printf("%s\n MAIN ", hashGenesisBlock.ToString().c_str());
    printf("%s\n MAIN ", genesis.hashMerkleRoot.ToString().c_str());
    printf("%x\n MAIN ", bnProofOfWorkLimit.GetCompact());
    printf("%d\n MAIN ", genesis.nNonce);

    assert(hashGenesisBlock == uint256("0x00000000579133b6ce9f275d5dfa9bcda51fcb6969ecb110ca90900b9fd2c3c1"));
    assert(genesis.hashMerkleRoot == uint256("0xbddc49f72d985b3d3469c6f38350621a4cea2b0830a965714831d9c5cbbd0052"));

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
    strSporkKey = "0453748e298a34e32d760a3d64b7b517c952c10024a4160a3a746d9bce572f85e13ac6d4f518ac110ba807ce19fb657bc2696ca02013290e3fbe517adf09c95787";
    strObfuscationPoolDummyAddress = "bDiJwVuKv9dcKBN4KCfX6UmXbkpqLfzGyf";
    nStartMasternodePayments = 1522886400;
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

    vAlertPubKey = ParseHex("04d5c87eab46ba486461d3d823d07ec46cd7f1de2dd21fece59b5bc7d87748898dc9b448b54a301565853c284bd01b98435e04709e27d4a3222fe79af05fe73f93");
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
    genesis.nTime = 1522856661;
    genesis.nNonce = 2433382384;
    genesis.nBits = bnProofOfWorkLimit.GetCompact();
    hashGenesisBlock = genesis.GetHash();

    printf("%s\n MAIN ", hashGenesisBlock.ToString().c_str());
    printf("%s\n MAIN ", genesis.hashMerkleRoot.ToString().c_str());
    printf("%x\n MAIN ", bnProofOfWorkLimit.GetCompact());
    printf("%d\n MAIN ", genesis.nNonce);

    assert(hashGenesisBlock == uint256("0x00000000a357a6ff798d3c8e72ce490fd0c646f0bfbfeb5167421add06a2ae8f"));
    assert(genesis.hashMerkleRoot == uint256("0xbddc49f72d985b3d3469c6f38350621a4cea2b0830a965714831d9c5cbbd0052"));

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
    strSporkKey = "04cd98bc62b2fa05711675243b1d86c181ea4c83e337f30ddcd8fbc1c937f550b4f539d53ee57789ebc8f6548fe3da21800eeea120d9ef8979452b8629526532c4";
    strObfuscationPoolDummyAddress = "TUQ57Fbh1crybrDhV6X9SDH95H4oSq4v6p";
    nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
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