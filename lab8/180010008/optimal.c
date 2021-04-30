#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define HIGH 20
#define FREQ 80
#define SAMPLES 20

typedef struct pte {
 int present;
} pte;

void init(int *sequence, int refs, int pages) {

int high = (int)(pages*((float)HIGH/100));

 for(int i = 0; i < refs; i++) {
  if(rand()%100 < FREQ) {
   sequence[i] = rand() % high;
   } else {
    sequence[i] = high + rand()%(pages - high);
  }
 }
}

int main(int argc, char *argv[]) {

 int refs = 100000;
 int pages = 100;
 
 pte *table = (pte *)malloc(pages*sizeof(pte));
 
 int *sequence = (int*)malloc(refs*sizeof(int));
 
 init(sequence, refs, pages);
 
 printf("# This is a benchmark of random replacement\n");
 printf("# %d page references\n", refs);
 printf("# %d pages \n", pages);
 printf("#\n#\n#frames\tratio\n");
 
 int frames;
 
 int incr = pages/SAMPLES;
 
 for(frames = incr; frames <= pages; frames += incr) {
 
 clear_page_table(table, pages);
 
 int hits = simulate(sequence, table, refs, frames, pages);
 
 float ratio = (float)hits/refs;
 
 printf("%d\t%.2f\n", frames, ratio);
 
 } 
 
 printf("\n");
 
 return 0;

}

void clear_page_table(pte *page_table, int pages) {
for(int i = 0; i < pages; i++) {
 page_table[i].present = 0;
 }
}

int simulate(int *seq, pte *table, int refs, int frms, int pgs) {

int hits = 0;
int allocated = 0;

int i;

for(i = 0; i < refs; i++) {
int next = seq[i];
pte *entry = &table[next];

if(entry->present == 1) {
 hits++;
 } else {
  if(allocated < frms) {
   allocated++;
   entry->present = 1;
  } else {
   pte *evict; 
   int sofar = 0;
   int candidate = pgs;
   
   for(int c = 0; c < pgs; c++) {
    if(table[c].present == 1) {
     int dist = 0;
     while(seq[i+dist] != c && i+dist < refs) {
      dist++;
     }
     if(dist > sofar) {
      candidate = c;
      sofar = dist;
     }
    }
   }
   evict = &table[candidate];
  
   evict->present = 0;
   entry->present = 1;
  }
 }
}
return hits;

}
