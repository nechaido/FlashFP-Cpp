#include "audio_source.h"

float* audio_recognition::pcm_to_float(const int* pcm, int length) {
  if (length < 1) {
    return new float[];
  }
  float buffer_length = length / 2;
  float* buffer = new float[buffer_length];
  for (int i = 0; i < buffer_length; i++) {
    buffer[i] = ((short) (pcm[2 * i] & 0xFF) | (pcm[2 * i + 1] << 8))
        * (1.0f / 32767.0f);
  }
  return buffer;
}
