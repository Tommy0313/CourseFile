inside_network_voice = int(input())
outside_network_voice = int(input())
city_phone = int(input())
inside_network_message = int(input())
outside_network_message = int(input())
network_traffic = int(input())

fee_list = [[183,0.08,0.139,0.135,1.128,1.483,1,250],[383,0.07,0.130,0.121,1.128,1.483,3,200],[983,0.06,0.108,0.101,1.128,1.483,5,150],[1283,0.05,0.100,0.090,1.128,1.483,0,0]]

payment_list = []

for fee in fee_list:
    if(network_traffic > fee[6]):
        network_traffic_need_pay = network_traffic - fee[6]
    else:
        network_traffic_need_pay = 0

    payment = fee[1]*inside_network_voice + fee[2]*outside_network_voice + fee[3]*city_phone + fee[4]*inside_network_message + fee[5]*outside_network_message + fee[7]*network_traffic_need_pay

    if(payment < fee[0]):
        payment = fee[0]

    payment_list.append(payment)

print(int(min(payment_list)))
print(fee_list[payment_list.index(min(payment_list))][0])