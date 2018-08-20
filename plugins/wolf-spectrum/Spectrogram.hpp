#ifndef SPECTROGRAM_HPP_INCLUDED
#define SPECTROGRAM_HPP_INCLUDED

#include "DistrhoPluginInfo.h"
#include "NanoVG.hpp"

#include "fft.hpp"

START_NAMESPACE_DISTRHO

class Spectrogram : public NanoWidget
{
public:
  Spectrogram(UI *ui, NanoWidget *widget, Size<uint> size);
  ~Spectrogram();

  void process(float **samples, uint32_t numSamples);
  
  void setSamples(float **samples);
  void setParameterValue(uint32_t i, float v);
  void onNanoDisplay();

private:
  UI *fUI;
  float **fSamples;
  
  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Spectrogram)
};

END_NAMESPACE_DISTRHO

#endif