#ifndef SRC_AUDIO_FORMAT_H_
#define SRC_AUDIO_FORMAT_H_

#include <string>

namespace audio_recognition {

struct AudioFormat {
  const int sample_rate;
  const int bits_per_sample;
  const int channels;
  const int frame_size;
  const bool is_signed;
  const bool is_big_endian;
};

}  // namespace audio_recognition

#endif //FLASHFP_CPP_AUDIO_FORMAT_H
