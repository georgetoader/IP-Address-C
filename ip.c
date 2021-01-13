#include <stdio.h>

unsigned int first_byte(unsigned int ip_addr) {
    return ip_addr >> 24;
}

unsigned int second_byte(unsigned int ip_addr) {
    return (ip_addr>>16) & 0xFF;
}

unsigned int third_byte(unsigned int ip_addr) {
    return (ip_addr>>8) & 0xFF;
}

unsigned int fourth_byte(unsigned int ip_addr) {
    return ip_addr & 0xFF;
}

//returns the subnet mask
unsigned int create_mask(unsigned int nr) {
    unsigned int mask = 0;
    for (int i = sizeof(unsigned int)*8-nr-1; i >= 0; i--) {
        mask = mask | (1<<i);
    }
    return ~mask;
}

//prints the IP address using the 4 bytes methods
void print_IP(unsigned int IP) {
    printf("%u.%u.%u.%u\n", first_byte(IP), second_byte(IP),
           third_byte(IP), fourth_byte(IP));
}

int main()
{
    unsigned int nrTest, msk_1, msk_2, ip_1, ip_2, n;
    //the 4 bytes
    unsigned int a, b, c, d;
    scanf("%u", &nrTest);

    for (unsigned int k=1;k<=nrTest;k++) {

        scanf("%u.%u.%u.%u", &a,&b,&c,&d);
        msk_1 = (a<<24) | (b<<16) | (c<<8) | (d);  //msk_1
        scanf("%u", &msk_2); 			//msk_2

        scanf("%u.%u.%u.%u", &a,&b,&c,&d);
        ip_1 = (a<<24) | (b<<16) | (c<<8) | (d);   //ip_1
        printf("%u\n", k);

        //TASK 0 - Print ip_1
        printf("-0 %u.%u.%u.%u/%u\n",a,b,c,d,msk_2);

        scanf("%u.%u.%u.%u", &a,&b,&c,&d);
        ip_2 = (a<<24) | (b<<16) | (c<<8) | (d);    //ip_2

        scanf("%u", &n);      			//n

        //TASK 1 - Create msk_2_b
        printf("-1 ");
        unsigned int msk_2_b=0;
        msk_2_b = create_mask(msk_2);
        print_IP(msk_2_b);

        //TASK 2 - Print msk_1 in octal and hexadecimal
        printf("-2 ");
        printf("%o.%o.%o.%o ",first_byte(msk_1),second_byte(msk_1),
               third_byte(msk_1),fourth_byte(msk_1));
        printf("%X.%X.%X.%X\n",first_byte(msk_1),second_byte(msk_1),
               third_byte(msk_1),fourth_byte(msk_1));

        //TASK 3 - Print the network address for ip_1
        printf("-3 ");
        unsigned int retea_IP_1 = msk_2_b & ip_1;
        print_IP(retea_IP_1);

        //TASK 4 - Print the broadcast address of ip_1
        printf("-4 ");
        unsigned int brd_IP_1 = ~(msk_2_b) | ip_1;
        print_IP(brd_IP_1);

        //TASK 5 - Check if ip_1 and ip_2 are part of the same network
        unsigned int retea_IP_2 = msk_2_b & ip_2;
        unsigned int result = retea_IP_2 ^ retea_IP_1;
        if (result==0) printf("-5 DA\n");
        else printf("-5 NU\n");

        //TASK 6-7 - Check if msk_1 is valid and if not then make it valid
        unsigned int valid = msk_1 & ((~msk_1) >> 1);
        if (valid==0) {
            printf("-6 DA\n");
            printf("-7 ");
            print_IP(msk_1);
        } else {
            printf("-6 NU\n");
            int nr=0;
            while (valid!=0) {
                valid = valid>>1;
                nr++;
            }
            msk_1 = msk_1>>nr;
            msk_1 = msk_1<<nr;
            printf("-7 ");
            print_IP(msk_1);
        }

        //TASK 8 - Print ip_1 in binary.
        printf("-8 ");
        for (int i=1;i<=4;i++) {
            if (i==1) a = first_byte(ip_1);
            else if (i==2) a = second_byte(ip_1);
            else if (i==3) a = third_byte(ip_1);
            else if (i==4) a = fourth_byte(ip_1);
        //compar fiecare bit din octet cu 1 folosind o masca
            for (unsigned int mask=1<<7; mask>0; mask=mask>>1) {
                if (a & mask) printf("1");
                else printf("0");
            }
            if (i!=4) printf(".");
        }
        printf("\n");

        //TASK 9 - Print indices of networks ip_2 could be part of.
        printf("-9");
        for (unsigned int i=0;i<n;i++) {
            unsigned int msk_net, net, retea_net;
            scanf("%u.%u.%u.%u/%u", &a,&b,&c,&d,&msk_net);
            unsigned int msk_net_b = create_mask(msk_net);
            net = (a<<24) | (b<<16) | (c<<8) | (d);
            retea_net = msk_net_b & net;
            retea_IP_2 = msk_net_b & ip_2;
            if (retea_net ^ retea_IP_2 == 0) printf(" %u",i);
        }
        printf("\n");
    }

    return 0;
}
