/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/


#include "PluginProcessor.h"
#include "PluginEditor.h"



//==============================================================================
StereoFilterAudioProcessor::StereoFilterAudioProcessor()
{

	lpLeftFreq_ = 20000;
	hpLeftFreq_ = 26;
	lpRightFreq_ = 20000;
	hpRightFreq_ = 26;
	lpQLeftFreq_ = 1.0;
	hpQLeftFreq_ = 1.0;
	lpQRightFreq_ = 1.0;
	hpQRightFreq_ = 1.0;


	
}

StereoFilterAudioProcessor::~StereoFilterAudioProcessor()
{
}

//==============================================================================
const String StereoFilterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int StereoFilterAudioProcessor::getNumParameters()
{
	return kNumParameters;
}

float StereoFilterAudioProcessor::getParameter(int index)
{
	switch (index)
	{			
	case kLPFreqLeftParam:				return lpLeftFreq_;
	case kHPFreqLeftParam:				return hpLeftFreq_;
	case kLPFreqRightParam:				return lpRightFreq_;
	case kHPFreqRightParam:				return hpRightFreq_;
	case kLPQFreqLeftParam:				return lpQLeftFreq_;
	case kHPQFreqLeftParam:				return hpQLeftFreq_;
	case kLPQFreqRightParam:			return lpQRightFreq_;
	case kHPQFreqRightParam:			return hpQRightFreq_;

		default:               return 0.0f;
	}
}


void StereoFilterAudioProcessor::setParameter(int index, float newValue)
{
	switch (index)
	{
	case kLPFreqLeftParam:
		lpLeftFreq_ = newValue;
		break;
	case kHPFreqLeftParam:
		hpLeftFreq_ = newValue;
		break;
	case kLPFreqRightParam:
		lpRightFreq_ = newValue;
		break;
	case kHPFreqRightParam:
		hpRightFreq_ = newValue;
		break;
	case kLPQFreqLeftParam:
		lpQLeftFreq_ = newValue;
		break;
	case kHPQFreqLeftParam:
		hpQLeftFreq_ = newValue;
		break;
	case kLPQFreqRightParam:
		lpQRightFreq_ = newValue;
		break;
	case kHPQFreqRightParam:
		hpQRightFreq_ = newValue;
		break;
	default:
		break;
	}

}

const String StereoFilterAudioProcessor::getParameterName(int index)
{
	switch (index)
	{
	case kLPFreqLeftParam:        return "left lowPass";
	case kHPFreqLeftParam:        return "left highPass";
	case kLPFreqRightParam:        return "right lowPass";
	case kHPFreqRightParam:        return "right highPass";
	case kLPQFreqLeftParam:        return "left Resonance";
	case kHPQFreqLeftParam:        return "left Resonance";
	case kLPQFreqRightParam:        return "right Resonance";
	case kHPQFreqRightParam:        return "right Resonance";

	default:               break;
	}
}

const String StereoFilterAudioProcessor::getParameterText(int index)
{
	return String(getParameter(index), 2);
}

bool StereoFilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool StereoFilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool StereoFilterAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double StereoFilterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int StereoFilterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int StereoFilterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void StereoFilterAudioProcessor::setCurrentProgram (int index)
{
}

const String StereoFilterAudioProcessor::getProgramName (int index)
{
    return {};
}

void StereoFilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void StereoFilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	lastSampleRate = sampleRate;



	monoFilterHighPLeft.setCoefficients(IIRCoefficients::makeHighPass(lastSampleRate, hpLeftFreq_, hpQLeftFreq_));
	monoFilterLowPLeft.setCoefficients(IIRCoefficients::makeLowPass(lastSampleRate, lpLeftFreq_, lpQLeftFreq_));
	monoFilterHighPRight.setCoefficients(IIRCoefficients::makeHighPass(lastSampleRate, hpRightFreq_, hpQRightFreq_));
	monoFilterLowPRight.setCoefficients(IIRCoefficients::makeLowPass(lastSampleRate, lpRightFreq_, lpQRightFreq_));

}


void StereoFilterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool StereoFilterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void StereoFilterAudioProcessor::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{

	monoFilterHighPLeft.setCoefficients(IIRCoefficients::makeHighPass(lastSampleRate, hpLeftFreq_, hpQLeftFreq_));
	monoFilterLowPLeft.setCoefficients(IIRCoefficients::makeLowPass(lastSampleRate, lpLeftFreq_, lpQLeftFreq_));
	monoFilterHighPRight.setCoefficients(IIRCoefficients::makeHighPass(lastSampleRate, hpRightFreq_, hpQRightFreq_));
	monoFilterLowPRight.setCoefficients(IIRCoefficients::makeLowPass(lastSampleRate, lpRightFreq_, lpQRightFreq_));

	

		float *leftChannel = buffer.getWritePointer(0);
		float *rightChannel = buffer.getWritePointer(1);

		
		monoFilterHighPLeft.processSamples(leftChannel, buffer.getNumSamples());
		monoFilterLowPLeft.processSamples(leftChannel, buffer.getNumSamples());

		monoFilterHighPRight.processSamples(rightChannel, buffer.getNumSamples());
		monoFilterLowPRight.processSamples(rightChannel, buffer.getNumSamples());
}




//==============================================================================
bool StereoFilterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* StereoFilterAudioProcessor::createEditor()
{
    return new StereoFilterAudioProcessorEditor (*this);
}

//==============================================================================
void StereoFilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

	XmlElement xml("MIDSIDEEQSETTINGS");

	//Set attributes.
	for (int i = 0; i < kNumParameters; ++i) {
		xml.setAttribute(getParameterName(i), getParameter(i));
	}

	//Dump to the given memory block.
	copyXmlToBinary(xml, destData);
}

void StereoFilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
	// This getXmlFromBinary() helper function retrieves our XML from the binary blob..
	ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));

	//Parse it all out.
	if (xmlState != nullptr) {
		//Make sure that we've got the right data.
		if (xmlState->hasTagName("MIDSIDEEQSETTINGS")) {
			//Pull information and push it to our plugin.
			for (int i = 0; i <  kNumParameters; ++i) {
				setParameter(i, (float)xmlState->getDoubleAttribute(getParameterName(i), getParameter(i)));
			}
		}
	}

}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new StereoFilterAudioProcessor();
}
