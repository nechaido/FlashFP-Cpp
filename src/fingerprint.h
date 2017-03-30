#ifndef SRC_FINGERPTINT_H_
#define SRC_FINGERPTINT_H_

#include "event_point.h"

namespace audio_recognition {

struct FingerPrint {

  const int t1;
  const int f1;
  const double f1_estimate;

  const int t2;
  const int f2;
  const double f2_estimate;

  double energy;

  EventPoint p1;
  EventPoint p2;

  bool operator=(FingerPrint fingerprint);

  int hash();
};

}  // namespace audio_recognition

#endif // SRC_FINGERPTINT_H_
