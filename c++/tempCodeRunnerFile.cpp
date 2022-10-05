void hamming()

{
    int ham[12], i;
    printf("\nEnter the data bits: ");
    for (i = 1; i <= 11; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 8)
            continue;
        else
            scanf("%d", &ham[i]);
    }
    ham[1] = ham[3] ^ ham[5] ^ ham[7] ^ ham[9] ^ ham[11];
    ham[2] = ham[3] ^ ham[6] ^ ham[7] ^ ham[10] ^ ham[11];
    ham[4] = ham[5] ^ ham[6] ^ ham[7];
    ham[8] = ham[9] ^ ham[10] ^ ham[11];
    printf("\nHamming code is: ");
    for (i = 1; i <= 11; i++)
        printf("%d ", ham[i]);
    printf("\nParity bits are: ");
    for (i = 1; i <= 11; i++)
    {
        if (i == 1 || i == 2 || i == 4 || i == 8)
            printf("%d ", ham[i]);
    }
}