#include <iostream>
#include <cmath>
using namespace std;
int main()
    {
        int i, nHeight, nDecreasePeriod, nSubsidyPeriods;
        float nSubsidyDP, nSubsidy;
        nHeight = 985242;
        nSubsidyDP = .125;
        nDecreasePeriod = 86400;
        nSubsidyPeriods = floor(nHeight/nDecreasePeriod);
        nSubsidy = 50;

        i = 0;

        while ( nHeight >= 86400 )
        {
            i++;
            int startblock;
            startblock = 1;
            cout << " Blocks " << i * nDecreasePeriod << " through " << (i * nDecreasePeriod) + nDecreasePeriod << " is period " << i << "\n";
            cout << "Period " << i << " nsubsidy is " << nSubsidy << " - ( " << nSubsidyDP << " * " << nSubsidy << " ) = " << nSubsidy - (nSubsidyDP * nSubsidy) << "\n";
            nSubsidy = (nSubsidy - (nSubsidyDP * nSubsidy) * COIN);
            if ( i == nSubsidyPeriods)

			break;
        }
        cout << "The Block Reward for block number " << nHeight << " is " << nSubsidy << "\n";
        return nSubsidy;
    }
	int64_t GetBlockValue(int nHeight) 
	//This bit of code is what calculates the block value and calculates what is traditionally referred to as halving.
	// in Fantasy Gold, we have referred to this as the SubsidyDecrease
	{
		int64_t nSubsidy = 0;
		int nSubsidyDecreasePeriod, nSubsidyPeriod;
		float nSubsidyDecreasePercent;
		nSubsidyDecreasePercent = .125; //Subsidy Decrease Percentage Per Period
		nSubsidyDecreasePeriod = 86400; //Number of Blocks in the desired time period for the reward to decrease.
		//this could also be obtained by using the desired time period in days (90) * 24 hours * 60 minutes * 60 seconds ) / blocktime (90) = 86,400
		//in fact maybe we should initialize the variables in chainparams... using something like the following:
		// Params().nRewardDecrease.days Params().nTargetSpacing Params().nRewardDecrease.percentperperiod 
		// nDecreasePeriod = (Params().nRewardDecrease.Days * 24 * 60 * 60) / Params().nTargetSpacing
		// in this codebase this is unnecessary because our decrease period is 90 days and our block spacing is 90 days thus 86400 is the amount of blocks in days
		// as well as the amount of blocks in seconds.
		nSubsidyPeriod = floor(nHeight/nDecreasePeriod); //This calculates which period of subsidy decrease the current block is in, if this is 0 then the reward is 50
		if (Params().NetworkID() == CBaseChainParams::TESTNET) {
			int nDecreasePeriodTestnet, nSubsidyPeriodTestnet;
			nDecreasePeriodTestnet = 100;
			nSubsidyPeriodTestnet = floor(nHeight/nDecreasePeriodTestnet);
			i = 0;
			while (nSubsidyPeriodTestnet >= 1) {
				i++;
				nSubsidy = (nSubsidy - (nSubsidyDecreasePercent * nSubsidy) * COIN);
				if ( i == nSubsidyPeriodTestnet)
					break;
			} 
		}
		if (nHeight == 0) {
			nSubsidy = 4750000 * COIN;
		}
		else if (nSubsidyDecreasePeriod < 1) {
			nSubsidy = 50 * COIN;
		}
		else {
			i = 0;
			while (nSubsidyPeriod >= 1) {
            i++;
			nSubsidy = (nSubsidy - (nSubsidyDecreasePercent * nSubsidy) * COIN);
            if ( i == nSubsidyPeriod)
				break;
		} 
		return nSubsidy;
	}
