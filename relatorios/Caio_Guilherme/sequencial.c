#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct candidate
{
    int candidate_id;
    int votes_amount;
} typedef Candidate;

typedef int item;
#define key(A) (A)
#define less(A, B) (key(A) > key(B))
#define exch(A, B) { item t = A; A = B, B = t; }
#define cmp(A,B) {if ((B - A) == 0) }
#define cmpexch(A, B){ if (less(B, A)) exch(A, B); }

static Candidate candidates[99999] = { 0,0 };
int compare_candidates(const void *a, const void *b);


int main(void) {
    int electedSenator, electedFederalCongressMen, electedStateCongressMen, vote;
    scanf("%d %d %d", &electedSenator, &electedFederalCongressMen, &electedStateCongressMen);


    int presidentVotesAmount = 0, validatedVotesAmount = 0, invalidVotesAmount = 0;
    while(scanf("%d", &vote) != EOF) {
        if (vote > 0) {
            validatedVotesAmount++;
            candidates[vote].candidate_id = vote;
            candidates[vote].votes_amount++;
        }
        else {
            invalidVotesAmount++;
        }
    }

    for (int i = 0; i < 100; i++) {
        presidentVotesAmount += candidates[i].votes_amount;
    }

    qsort(candidates, 99, sizeof(Candidate), compare_candidates);

    printf("%d %d\n", validatedVotesAmount, invalidVotesAmount);

    if (candidates[0].votes_amount > (presidentVotesAmount / 2)) 
        printf("%d\n",candidates[0].candidate_id);
    else
        printf("Segundo turno\n");
    
    qsort(candidates + 100, 900, sizeof(Candidate), compare_candidates);

    for (int i = 0; i < electedSenator; i++) {
        printf("%d", candidates[i + 100].candidate_id);
        if (i != (electedSenator - 1))
            printf(" ");
    }

    printf("\n");

    qsort(candidates + 1000, 9000, sizeof(Candidate), compare_candidates);

    for (int i = 0; i < electedFederalCongressMen; i++) {
        printf("%d", candidates[i + 1000].candidate_id);
        if (i != (electedFederalCongressMen - 1))
            printf(" ");
    }

    printf("\n");

    qsort(candidates + 10000, 90000, sizeof(Candidate), compare_candidates);

    for (int i = 0; i < electedStateCongressMen; i++) {
        printf("%d", candidates[i + 10000].candidate_id);
        if (i != (electedStateCongressMen - 1))
            printf(" ");
    }

    printf("\n");


    return 0;
}

int compare_candidates(const void *a, const void *b) { 
    Candidate *votoA = (Candidate*) a;
    Candidate *votoB = (Candidate*) b;

    if ((votoB->votes_amount - votoA->votes_amount) == 0)
        return votoB->candidate_id - votoA->candidate_id;
    return (votoB->votes_amount - votoA->votes_amount);
}