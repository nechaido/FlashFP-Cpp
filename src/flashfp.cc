#include "flashfp.h"

#include "event_point_processor.h"

using namespace audio_recognition;

FlashFP::FlashFP(const Config* config, StorageProvider* storage) : config_(
    config), storage_(storage) {
}

FlashFP::~FlashFP() {
  delete config_;
  delete storage_;
}

bool FlashFP::store(AudioSource& audioSource, AudioInfo info) {
  if (storage_->contains(info)) {
    return false;
  }

  auto fingerprints = extractFingerprints(audioSource);
  auto hashes = std::list<int>();
  for (auto fingerprint : fingerprints) {
    hashes.push_back(fingerprint.hash());
  }
  storage_->addAudio(info, hashes);
  return true;
}

AudioInfo FlashFP::getAudioDescription(int id) {
  return storage_->getAuidioInfo(id);
}

std::list<QueryResult> FlashFP::match(AudioSource& audioSource) {
  return storage_->getMatches(extractFingerprints(audioSource));
}

std::list<QueryResult> FlashFP::match(AudioSource& audioSource, int limit) {
  auto matches = storage_->getMatches(extractFingerprints(audioSource));

  matches.sort([](const QueryResult& a, const QueryResult& b) {
    return a.score > b.score;
  });

  std::list<QueryResult> result;

  int size = limit > matches.size() ? limit : matches.size();
  auto current = matches.begin();
  for (int i = 0; i < size; i++, current++) {
    result.push_back(*current);
  }

  return result;
}

bool FlashFP::contains(AudioInfo info) {
  return storage_->contains(info);
}

std::list<FingerPrint> FlashFP::extractFingerprints(AudioSource& source) {
  return EventPointProcessor(config_).getFingerprints(source);
}
