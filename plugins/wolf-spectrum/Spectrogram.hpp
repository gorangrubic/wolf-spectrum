#ifndef SPECTROGRAM_HPP_INCLUDED
#define SPECTROGRAM_HPP_INCLUDED

#include "DistrhoPluginInfo.h"
#include "NanoVG.hpp"
#include "WolfSpectrumPlugin.hpp"
#include "ScrollingTexture.hpp"

START_NAMESPACE_DISTRHO

class Spectrogram : public NanoWidget
{
public:
  Spectrogram(UI *ui, NanoWidget *widget, Size<uint> size);
  ~Spectrogram();

  void process(float **samples, uint32_t numSamples);

  void setParameterValue(uint32_t i, float v);
  void onNanoDisplay();
  void setLogFrequencyScaling(bool yesno);
  void setBlockSize(int blockSize);
  void setHorizontalScrolling(bool yesno);

protected:
  void onResize(const ResizeEvent &ev) override;

private:
  UI *fUI;
  float **fSamples;
  bool fLogFrequencyScaling;
  ScrollingTexture fScrollingTexture;
  int fBlockSize;
  bool fHorizontalScrolling;

  DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Spectrogram)
};

END_NAMESPACE_DISTRHO

#endif