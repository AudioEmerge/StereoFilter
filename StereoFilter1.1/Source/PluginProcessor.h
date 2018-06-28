/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once


#include "../JuceLibraryCode/JuceHeader.h"





//==============================================================================
/**
*/
class StereoFilterAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    StereoFilterAudioProcessor();
    ~StereoFilterAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
	AudioProcessorEditor* createEditor();
	bool hasEditor() const;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect () const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	//==============================================================================
	int getNumParameters();

	float getParameter(int index);
	void setParameter(int index, float newValue);

	const String getParameterName(int index);
	const String getParameterText(int index);

	int lastUIWidth_, lastUIHeight_;

	enum Parameters
	{

		kLPFreqLeftParam = 0,
		kHPFreqLeftParam,
		kLPFreqRightParam,
		kHPFreqRightParam,
		kLPQFreqLeftParam,
		kHPQFreqLeftParam,
		kLPQFreqRightParam,
		kHPQFreqRightParam,
		kNumParameters
	
	};

	float lpLeftFreq_, hpLeftFreq_, lpRightFreq_, hpRightFreq_, lpQLeftFreq_, hpQLeftFreq_, lpQRightFreq_, hpQRightFreq_;



private:
    //==============================================================================

	IIRFilter monoFilterHighPLeft, monoFilterLowPLeft, monoFilterHighPRight, monoFilterLowPRight;

	float lastSampleRate;



    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoFilterAudioProcessor)
};
