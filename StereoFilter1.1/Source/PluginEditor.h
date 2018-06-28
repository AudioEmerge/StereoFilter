/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"




class FrequencyKnobLookAndFeel : public LookAndFeel_V4
{
public:
	FrequencyKnobLookAndFeel()
	{

		//setColour(Slider::textBoxOutlineColourId, Colours::grey.withAlpha(0.0f));


	}

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
	{



		// This is the binary image data that uses very little CPU when rotating

		Image freqKnobStrip = ImageCache::getFromMemory(BinaryData::FreqKnob_png, BinaryData::FreqKnob_pngSize);

		//Image myStrip = ImageCache::getFromMemory(BinaryData::ParamsRotaryKnob_png, BinaryData::ParamsRotaryKnob_pngSize);



		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); //value between 0 and 1 for current amount of rotation
		const int nFrames = freqKnobStrip.getHeight() / freqKnobStrip.getWidth(); // number of frames for vertical film strip
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0)); // current index from 0 --> nFrames-1

		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius - 1.0f;

		g.drawImage(freqKnobStrip,
			(int)rx,
			(int)ry,
			2 * (int)radius,
			2 * (int)radius,   //Dest
			0,
			frameIdx*freqKnobStrip.getWidth(),
			freqKnobStrip.getWidth(),
			freqKnobStrip.getWidth()); //Source


	}


};

class ResonanceKnobLookAndFeel : public LookAndFeel_V4
{
public:
	ResonanceKnobLookAndFeel()
	{

		//setColour(Slider::textBoxOutlineColourId, Colours::grey.withAlpha(0.0f));


	}

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
	{



		// This is the binary image data that uses very little CPU when rotating

		Image resKnobStrip = ImageCache::getFromMemory(BinaryData::ResKnob_png, BinaryData::ResKnob_pngSize);

		



		const double fractRotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum()); //value between 0 and 1 for current amount of rotation
		const int nFrames = resKnobStrip.getHeight() / resKnobStrip.getWidth(); // number of frames for vertical film strip
		const int frameIdx = (int)ceil(fractRotation * ((double)nFrames - 1.0)); // current index from 0 --> nFrames-1

		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centreX = x + width * 0.5f;
		const float centreY = y + height * 0.5f;
		const float rx = centreX - radius - 1.0f;
		const float ry = centreY - radius - 1.0f;

		g.drawImage(resKnobStrip,
			(int)rx,
			(int)ry,
			2 * (int)radius,
			2 * (int)radius,   //Dest
			0,
			frameIdx*resKnobStrip.getWidth(),
			resKnobStrip.getWidth(),
			resKnobStrip.getWidth()); //Source


	}


};

//==============================================================================
/**
*/
class StereoFilterAudioProcessorEditor   : public AudioProcessorEditor,
									   public Slider::Listener,
									   public Timer
{
public:
    StereoFilterAudioProcessorEditor  (StereoFilterAudioProcessor&);
    ~StereoFilterAudioProcessorEditor ();

    //==============================================================================
	void timerCallback();



	void paint (Graphics&) override;
    void resized() override;
	void sliderValueChanged(Slider* sliderThatWasMoved) override;


private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.

	Slider  lpLeftSlider_,lpLeftQSlider_, hpLeftSlider_, hpLeftQSlider_, lpRightSlider_, lpRightQSlider_, hpRightSlider_, hpRightQSlider_;
	Label lpLeftLabel_, hpLeftLabel_, qLPLeftLabel_, qHPLeftLabel_, lpRightLabel_, hpRightLabel_, qLPRightLabel_, qHPRightLabel_;
	GroupComponent leftGroup_, rightGroup_;
	FrequencyKnobLookAndFeel frequencyKnobLookAndFeel;
	ResonanceKnobLookAndFeel resonanceKnobLookAndFeel;
	StereoFilterAudioProcessor& processor;




	


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoFilterAudioProcessorEditor )
};
