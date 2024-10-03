#include <stdio.h>

/*
DUE TIPI DI SOTTOPROGRAMMI
- FUNZIONI --> Analoghe alle funzioni matematiche, ovvero hanno valori di ingresso (dominio) e di uscita (codominio)
- PROCEDURE --> Non hanno un valore di uscita

1 - Dichiarazione del prototipo della funzione
2 - Definizione della funzione
-----------------------------------------------
1 - Parte DIRETTIVE
    # include
    # define

2 - Parte DICHIARATIVA (globale)
    - DICHIARAZIONE TIPI (Struct)
    - DICHIARAZIONE PROTOTIPI di FUNZIONE

3 - PROGRAMMA PRINCIPALE (main)
    - DICHIARAZIONE VAR E COSTANTI (parte DICHIARATIVA)
    - PARTE ESECUTIVA

4 - DEFINIZIONE DELLE FUNZIONI
    - PARTE DICHIARATIVA
    - PARTE ESECUTIVA
-----------------------------------------------
2 - DICHIARAZIONE PROTOTIPO di FUNZIONE

<tipo_risultato> <nome_funzione> ( <lista_tipi_parametri> );
                                ( detti parametri formali )
-----------------------------------------------
4 - DEFINIZIONI DELLE FUNZIONI
                                    ( detti parametri formali )
<tipo_risultato> <nome_funzione> (<tipo_parametro> <nome_parametro>, ...){
    1 - PARTE DICHIARATIVA
    2 - PARTE ESECUTIVA

    RETURN <espressione>;
    RETURN; // solo se ha tipo void
};

INVOCAZIONE DI UNA FUNZIONE

    x = nome_funzione(p1, .... , pn);
                    ( parametri attuali ) <-- variabili | costanti | valori

                                            x = fattoriale(a);
                                            x = fattoriale(5);

INVOCAZIONE DI UNA PROCEDURA

    nome_procedura(p1, .... , pn);


Cosa succede quando invoco una funzione?

1 - PARAMETRI ATTUALI vengono COPIATI nei PARAMETRI FORMALI
2 - CONTROLLO di ESECUZIONE PASSA dalla FUNZIONE CHIAMANTE alla FUNZIONE CHIAMATA

*/

int pari(int);
void pari_2(int);

int main(void){
    int a = pari(2);
    pari_2(5);
    return 0;
}

// FUNZIONE
int pari(int x){
    if (x%2 == 0)
        return 1;
    else 
        return 0;
}

// PROCEDURA
void pari_2(int x){
    if (x%2 == 0)
        printf("Il numero %i e' pari\n", x);
    else 
        printf("Il numero %i e' dispari\n", x);
}