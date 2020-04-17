#include <stdio.h>
#include "sound.h"

WAVheader readwavhdr(FILE *fp){
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h) {
	for(int i=0; i<4; i++)
		printf("%c",h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n",h.chunkSize);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Bits per sample: %d \n",h.bitsPerSample);
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	printf("Duration: %f seconds\n",duration);
}
