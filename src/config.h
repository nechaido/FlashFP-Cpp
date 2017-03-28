#ifndef SRC_CONFIG_H_
#define SRC_CONFIG_H_

namespace audio_recognition {

struct Config {
  int sample_rate;
  int size;
  int step_size;

  int max_filter_window_size;
  int min_filter_windows_size;

  int max_event_points_per_frame;
  int max_fingerprinting_per_event_point;
  double min_distance;
};

}  // namespace audio_recognition

#endif  // SRC_CONFIG_H_
