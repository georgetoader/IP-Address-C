# ip-addresses
  
* `create_mask(unsigned int nr)` -> Primeste ca parametru numarul de biti setati pe care trebuie sa-i aiba masca de retea. Functia seteaza ultimii sizeof()-nr-1 biti in masca 'mask' si apoi returneaza complementa acesteia.

* `first_byte(unsigned int ip_addr), ..., fourth_byte(...)` -> Afiseaza unul din cei 4 octeti ai unei adrese.

* `print_IP(unsigned int IP)` -> Afiseaza adresa IP folosind cele 4 functii first_byte(...), ...

  ### TASK 0
  Am afisat fiecare byte al adresei ip_1 prin folosirea variabilelor a,b,c,d pe care le-am folosit la citire, urmata de '/' si msk_2.

  ### TASK 1
  Am folosit functia create_mask(msk_2) pentru a crea msk_2_b masca ceruta.

  ### TASK 2
  Pentru a afisa adresa in baza 8 si baza 16 am folosit proprietati ale functiei printf() cum ar fi %o pentru baza 8, respectiv %X pentru baza 16.

  ### TASK 3
  Am folosit operatia '&' intre ip_1 si msk_2_b creata la TASK_1 pentru a gasi retea_IP_1 si am afisat-o folosind print_IP(retea_IP_1).

  ### TASK 4
  Am folosit operatia '|' intre complementa mastii de retea msk_2_b si ip_1 pentru a gasi brd_IP_1 si am afisat-o folosind print_IP(brd_IP_1).

  ### TASK 5
  Am construit adresa de retea a lui ip_2 in retea_IP_2 si apoi am folosit operatia '^' intre adresele de retea a lui ip_1 si respectiv ip_2 pentru a vedea daca sunt identice. Daca sunt, atunci afisez "DA", altfel afisez "NU".

	### TASK 6
  Daca o masca de retea este valida atunci ar trebui sa aiba toti bitii setati consecutivi. Am inversat msk_1 si am shiftat bitii la dreapta o data, comparand-o apoi cu masca originala msk_1 prin '&'. In acest mod putem vedea daca dupa prima valoare de 0 dupa cei N biti setati mai exista alte valori de 1 prin inversarea acelui 0 (devenind astfel 1 si apoi daca shiftez la dreapta o sa corespunda unei valori de 1 din adresa initiala). Daca ar fi o masca valida atunci valoarea rezultata ar trebui sa fie egala cu 0.

	### TASK 7
  Daca la TASK 6 masca a fost valida atunci o afisez folosind print_IP(msk_1). Daca nu atunci incerc sa aflu pozitia primului bit de 1 dupa cel mai semnificativ bit de 0 prin shiftarea la dreapta a adresei rezultate la TASK_6 in continuu pana cand devine 0. Retin numarul de pasi intr-o variabila 'nr' iar apoi shiftez msk_1 de nr ori la dreapta si apoi de nr ori la stanga pentru a inlocui toate valorile invalide cu 0. Afisez apoi masca prin print_IP(msk_1);

	### TASK 8
  Folosesc un for cu 4 pasi corespunzatori celor 4 octeti si o variabila 'a' ce retine acel octet din adresa ip_1. Construiesc o masca ce incepe de la 10000000 si o shiftez cu cate 1 bit la dreapta cu ajutorul unui for si o compar cu variabila 'a' printr-un '&' pentru a vedea ce biti sunt setati in acel octet. Daca compararea da un rezultat diferit de 0 atunci printez "1" deoarece am gasit un bit setat, altfel printez "0".

	### TASK 9
  Folosesc un for pentru a parcurge cele N adrese de retea. Construiesc adresa 'net', masca de retea 'msk_net_b' si adresa de retea 'retea_net' prin operatia '&' a primelor doua. Construiesc adresa de retea a adresei ip_2 in 'retea_IP_2'. Daca cele 2 adrese 'net' si 'ip_2' ar face parte din aceeasi retea atunci ar trebui sa aiba aceeasi adresa de retea deci comparam prin '^' adresele 'retea_net' si 'retea_IP_2' pentru a vedea daca sunt identice. Daca da atunci afisez indicele 'i'. 
