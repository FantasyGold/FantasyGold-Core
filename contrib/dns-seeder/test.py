import socket

seeders = [
    'fgcseed.mempool.pw',
    'fgcseed1.fantasygold.io',
    'fgcseed2.fantasygold.io',
    'fgcseed3.fantasygold.io',
    'fgcseed4.fantasygold.io',
    'fgcseed5.fantasygold.io',
    'fgcseed1.fantasygoldcrypto.site',
    'fgcseed2.fantasygoldcrypto.site',
    'fgcseed3.fantasygoldcrypto.site',
    'fgcseed4.fantasygoldcrypto.site',
    'fgcseed5.fantasygoldcrypto.site'
]

for seeder in seeders:
    try:
        ais = socket.getaddrinfo(seeder, 0)
    except socket.gaierror:
        ais = []
    
    # Prevent duplicates, need to update to check
    # for ports, can have multiple nodes on 1 ip.
    addrs = []
    for a in ais:
        addr = a[4][0]
        if addrs.count(addr) == 0:
            addrs.append(addr)
    
    print(seeder + ' = ' + str(len(addrs)))
