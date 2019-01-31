# Masternode Commands

`systemctl start fantasygoldd`
\- Starts the FantasyGold Daemon

`systemctl stop fantasygoldd`
\- Stops the FantasyGold Daemon

`systemctl restart fantasygoldd`
\- Restarts the FantasyGold Daemon

`systemctl status fantasygoldd`
\- Displays the status of the FantasyGold Daemon

`fantasygold-cli masternode status`
\- Displays the status of the FantasyGold masternode running on the VPS

`fantasygold-cli getinfo`
\- Displays general info about the masternode

`fantasygold-cli masternodecurrent`
\- Displays additional info about the masternode

`ps aux | grep fantasygold`
\- Shows if the fantasygoldd process is running

`dmesg | egrep -i 'killed process'`
\- Lets you know whether fantasygoldd was killed due to lack of memory

`nano ~/.fantasygold/fantasygold.conf`
\- Edits your fantasygold.conf file

`killall -9 fantasygoldd`
\- Force quits fantasygoldd (*USE WITH CAUTION*)

`fantasygold-cli getpeerinfo | grep synced_headers`
\- Displays synced headers

`fantasygold-cli getmasternodecount`
\- Displays count of all masternodes

`bash <( curl https://raw.githubusercontent.com/FantasyGold/FantasyGold-Core.git-MN-Install/master/refresh_node.sh )`

Refreshes your node by clearing the chaindata

`bash <( curl https://raw.githubusercontent.com/FantasyGold/FantasyGold-Core.git-MN-Install/master/update_node.sh )`

Updates your node to the newest version
