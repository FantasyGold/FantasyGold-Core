import socket

seeders = [
    'bwkseed.mempool.pw',
    'bwkseed1.fantasygoldcrypto.com',
    'bwkseed2.fantasygoldcrypto.com',
    'bwkseed3.fantasygoldcrypto.com',
    'bwkseed4.fantasygoldcrypto.com',
    'bwkseed5.fantasygoldcrypto.com',
    'bwkseed1.fantasygoldcrypto.site',
    'bwkseed2.fantasygoldcrypto.site',
    'bwkseed3.fantasygoldcrypto.site',
    'bwkseed4.fantasygoldcrypto.site',
    'bwkseed5.fantasygoldcrypto.site'
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
