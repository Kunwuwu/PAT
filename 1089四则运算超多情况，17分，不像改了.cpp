#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long gcd(long a, long b)
{
    if(b == 0)
        return abs(a);
    else
        return gcd(b, a % b);
}

int main()
{
    long a1, b1, a2, b2;                                       /* b1, b2也要考虑等于零的情况，不想改了，蛋疼 */
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
    long integera1 = 1, fraca1 = 1, gcdvalue = 1, fracb1 = 1;
    if(b1 != 0)
    {
        fraca1 = a1 % b1;
        integera1= a1 / b1;
        gcdvalue = gcd(fraca1, b1);
        fraca1 /= gcdvalue;
        fracb1 = b1 / gcdvalue;
    }

    long integera2 = 1;
    long fraca2 = 1, fracb2 = 1;
    if(b2 != 0)
    {
        integera2 = a2 / b2;
        fraca2 = a2 % b2;
        gcdvalue = gcd(fraca2, b2);
        fraca2 /= gcdvalue;
        fracb2 = b2 / gcdvalue;
    }


    long suma = 0, sumb = 0;
    suma = a1 * b2 + a2 * b1;
    sumb = b1 * b2;
    long integersum = suma / sumb;
    long fracsum = suma % sumb;
    long gcdvaluesum = gcd(sumb, fracsum);
    if(integera1 >= 0)
    {
        if(integera1 != 0) cout << integera1 << " ";
        if(a1 > 0) printf("%ld/%ld", fraca1, fracb1);
        else if(a1 < 0) printf("(%ld/%ld)", fraca1, fracb1);
        if(integera1 == 0 && fraca1 == 0) printf("0");
    }
    else
    {
        if(fraca1 != 0) printf("(%ld %ld/%ld)", integera1, abs(fraca1), fracb1);
        else printf("(%ld)", integera1);
    }
    printf(" + ");
    if(integera2 >= 0)
    {
        if(integera2 != 0) cout << integera2 << " ";
        if(a2 > 0) printf("%ld/%ld", fraca2, fracb2);
        else if(a2 < 0) printf("(%ld/%ld)", fraca2, fracb2);
        if(integera2 == 0 && fraca2 == 0) printf("0");
    }
    else
    {
        if(fraca2 != 0) printf("(%ld %ld/%ld)", integera2, abs(fraca2), fracb2);
        else printf("(%ld)", integera2);
    }
    printf(" = ");
    if(integersum >= 0)
    {
        if(integersum > 0) cout << integersum << " ";
        if(fracsum > 0) printf("%ld/%ld", fracsum / gcdvaluesum, sumb / gcdvaluesum);
        else if(fracsum < 0) printf("(%ld/%ld)", fracsum / gcdvaluesum, sumb / gcdvaluesum);
        if(fracsum == 0 && integersum == 0) printf("0");
    }
    else
    {
        if(fracsum != 0) printf("(%ld %ld/%ld)", integersum, abs(fracsum / gcdvaluesum), sumb / gcdvaluesum);
        else printf("(%ld)", integersum);
    }
    printf("\n");


    long diffa = 0;
    diffa = a1 * b2 - a2 * b1;
    long integerdiff = diffa / sumb;
    long fracdiff = diffa % sumb;
    long gcdvaluediff = gcd(fracsum, sumb);
    if(integera1 >= 0)
    {
        if(integera1 != 0) cout << integera1 << " ";
        if(a1 > 0) printf("%ld/%ld", fraca1, fracb1);
        else if(a1 < 0) printf("(%ld/%ld)", fraca1, fracb1);
        if(integera1 == 0 && fraca1 == 0) printf("0");
    }
    else
    {
        if(fraca1 != 0) printf("(%ld %ld/%ld)", integera1, abs(fraca1), fracb1);
        else printf("(%ld)", integera1);
    }
    printf(" - ");
    if(integera2 >= 0)
    {
        if(integera2 != 0) cout << integera2 << " ";
        if(a2 > 0) printf("%ld/%ld", fraca2, fracb2);
        else if(a2 < 0) printf("(%ld/%ld)", fraca2, fracb2);
        if(integera2 == 0 && fraca2 == 0) printf("0");
    }
    else
    {
        if(fraca2 != 0) printf("(%ld %ld/%ld)", integera2, abs(fraca2), fracb2);
        else printf("(%ld)", integera2);
    }
    printf(" = ");
    if(integerdiff >= 0)
    {
        if(integerdiff != 0) printf("%ld ", integerdiff);
        if(fracdiff > 0) printf("%ld/%ld", fracdiff / gcdvaluediff, sumb / gcdvaluediff);
        else if(fracdiff < 0) printf("(%ld/%ld)", fracdiff / gcdvaluediff, sumb / gcdvaluediff);
        if(fracdiff == 0 && integerdiff == 0) printf("0");
    }
    else
    {
        if(fracdiff != 0) printf("(%ld %ld/%ld)", integerdiff, abs(fracdiff / gcdvaluediff), sumb / gcdvaluediff);
        else printf("(%ld)", integerdiff);
    }
    printf("\n");

    long prda = a1 * a2;
    long prdb = b1 * b2;
    long integerprd  = prda / prdb;
    long fracprd = prda % prdb;
    long gcdvalueprd = gcd(fracprd, prdb);
    if(integera1 >= 0)
    {
        if(integera1 != 0) cout << integera1 << " ";
        if(a1 > 0) printf("%ld/%ld", fraca1, fracb1);
        else if(a1 < 0) printf("(%ld/%ld)", fraca1, fracb1);
        if(integera1 == 0 && fraca1 == 0) printf("0");
    }
    else
    {
        if(fraca1 != 0) printf("(%ld %ld/%ld)", integera1, abs(fraca1), fracb1);
        else printf("(%ld)", integera1);
    }
    printf(" * ");
    if(integera2 >= 0)
    {
        if(integera2 != 0) cout << integera2 << " ";
        if(a2 > 0) printf("%ld/%ld", fraca2, fracb2);
        else if(a2 < 0) printf("(%ld/%ld)", fraca2, fracb2);
        if(integera2 == 0 && fraca2 == 0) printf("0");
    }
    else
    {
        if(fraca2 != 0) printf("(%ld %ld/%ld)", integera2, abs(fraca2), fracb2);
        else printf("(%ld)", integera2);
    }
    printf(" = ");
    if(integerprd >= 0)
    {
        if(integerprd != 0) printf("%ld ", integerprd);
        if(fracprd > 0) printf("%ld/%ld", fracprd / gcdvalueprd, prdb / gcdvalueprd);
        else if(fracprd < 0) printf("(%ld/%ld)", fracprd / gcdvalueprd, prdb / gcdvalueprd);
        if(fracprd == 0 && integerprd == 0) printf("0");
    }
    else
    {
        if(fracprd != 0) printf("(%ld %ld/%ld)", integerprd, abs(fracprd / gcdvalueprd), prdb / gcdvalueprd);
        else printf("(%ld)", integerprd);
    }
    printf("\n");

    if(integera1 >= 0)
    {
        if(integera1 != 0) cout << integera1 << " ";
        if(a1 > 0) printf("%ld/%ld", fraca1, fracb1);
        else if(a1 < 0) printf("(%ld/%ld)", fraca1, fracb1);
        if(integera1 == 0 && fraca1 == 0) printf("0");
    }
    else
    {
        if(fraca1 != 0) printf("(%ld %ld/%ld)", integera1, abs(fraca1), fracb1);
        else printf("(%ld)", integera1);
    }
    printf(" / ");
    if(integera2 >= 0)
    {
        if(integera2 != 0) cout << integera2 << " ";
        if(a2 > 0) printf("%ld/%ld", fraca2, fracb2);
        else if(a2 < 0) printf("(%ld/%ld)", fraca2, fracb2);
        if(integera2 == 0 && fraca2 == 0) printf("0");
    }
    else
    {
        if(fraca2 != 0) printf("(%ld %ld/%ld)", integera2, abs(fraca2), fracb2);
        else printf("(%ld)", integera2);
    }
    printf(" = ");
    if(a2 != 0)
    {
        long quoa = a1 * b2;
        long quob = b1 * a2;
        long integerquo = quoa / quob;
        long fracquo = quoa % quob;
        long gcdvaluequo = gcd(fracquo, quob);
        if(integerquo >= 0)
        {
            if(integerquo != 0) printf("%ld ", integerquo);
            if(fracquo > 0 && quob > 0) printf("%ld/%ld", fracquo / gcdvaluequo, quob / gcdvaluequo);
            else if(fracquo < 0 || quob < 0) printf("(-%ld/%ld)", abs(fracquo / gcdvaluequo), abs(quob / gcdvaluequo));
            if(fracquo == 0 && integerquo == 0) printf("0");
        }
        else
        {
            if(fracquo != 0) printf("(%ld %ld/%ld)", integerquo, abs(fracquo / gcdvaluequo), quob / gcdvaluequo);
            else printf("(%ld)", integerquo);
        }
    }
    else
        printf("Inf");

    return 0;
}
