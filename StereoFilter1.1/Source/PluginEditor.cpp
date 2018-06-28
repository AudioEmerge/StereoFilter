/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"


//==============================================================================
StereoFilterAudioProcessorEditor::StereoFilterAudioProcessorEditor(StereoFilterAudioProcessor& p)
	: AudioProcessorEditor(&p), processor(p),
	lpLeftLabel_("", "Low Pass"),
	hpLeftLabel_("", "High Pass"),
	qLPLeftLabel_("", "Resonance"),
	qHPLeftLabel_("", "Resonance"),
	lpRightLabel_("", "Low Pass"),
	hpRightLabel_("", "High Pass"),
	qLPRightLabel_("", "Resonance"),
	qHPRightLabel_("", "Resonance")

{

	//GroupComponents
	addAndMakeVisible(leftGroup_);
	leftGroup_.setText("Left Filter");
	leftGroup_.setColour(GroupComponent::outlineColourId, Colours::white);

	addAndMakeVisible(rightGroup_);
	rightGroup_.setText("Right Filter");

	//Sliders
	addAndMakeVisible(lpLeftSlider_);
	lpLeftSlider_.setRange(26, 20000, 1);
	lpLeftSlider_.setSliderStyle(Slider::Rotary);
	lpLeftSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	lpLeftSlider_.addListener(this);

	addAndMakeVisible(lpLeftQSlider_);
	lpLeftQSlider_.setRange(0.0, 5.0, 0.1);
	lpLeftQSlider_.setSliderStyle(Slider::Rotary);
	lpLeftQSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	lpLeftQSlider_.addListener(this);

	addAndMakeVisible(hpLeftSlider_);
	hpLeftSlider_.setRange(26, 19000, 1);
	hpLeftSlider_.setSliderStyle(Slider::Rotary);
	hpLeftSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	hpLeftSlider_.addListener(this);

	addAndMakeVisible(hpLeftQSlider_);
	hpLeftQSlider_.setRange(0.0, 5.0, 0.1);
	hpLeftQSlider_.setSliderStyle(Slider::Rotary);
	hpLeftQSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	hpLeftQSlider_.addListener(this);


	addAndMakeVisible(lpRightSlider_);
	lpRightSlider_.setRange(26, 20000, 1);
	lpRightSlider_.setSliderStyle(Slider::Rotary);
	lpRightSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	lpRightSlider_.addListener(this);

	addAndMakeVisible(lpRightQSlider_);
	lpRightQSlider_.setRange(0.0, 5.0, 0.1);
	lpRightQSlider_.setSliderStyle(Slider::Rotary);
	lpRightQSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	lpRightQSlider_.addListener(this);

	addAndMakeVisible(hpRightSlider_);
	hpRightSlider_.setRange(26, 19000, 1);
	hpRightSlider_.setSliderStyle(Slider::Rotary);
	hpRightSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	hpRightSlider_.addListener(this);

	addAndMakeVisible(hpRightQSlider_);
	hpRightQSlider_.setRange(0.0, 5.0, 0.1);
	hpRightQSlider_.setSliderStyle(Slider::Rotary);
	hpRightQSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 80, 20);
	hpRightQSlider_.addListener(this);


	//Labels

	lpLeftLabel_.attachToComponent(&lpLeftSlider_, false);
	lpLeftLabel_.setFont(Font(12.0f));

	hpLeftLabel_.attachToComponent(&hpLeftSlider_, false);
	hpLeftLabel_.setFont(Font(12.0f));

	qLPLeftLabel_.attachToComponent(&lpLeftQSlider_, false);
	qLPLeftLabel_.setFont(Font(12.0f));

	qHPLeftLabel_.attachToComponent(&hpLeftQSlider_, false);
	qHPLeftLabel_.setFont(Font(12.0f));

	lpRightLabel_.attachToComponent(&lpRightSlider_, false);
	lpRightLabel_.setFont(Font(12.0f));

	hpRightLabel_.attachToComponent(&hpRightSlider_, false);
	hpRightLabel_.setFont(Font(12.0f));

	qLPRightLabel_.attachToComponent(&lpRightQSlider_, false);
	qLPRightLabel_.setFont(Font(12.0f));

	qHPRightLabel_.attachToComponent(&hpRightQSlider_, false);
	qHPRightLabel_.setFont(Font(12.0f));

	//Apply LookAndFeel
	lpLeftSlider_.setLookAndFeel(&frequencyKnobLookAndFeel);
	hpLeftSlider_.setLookAndFeel(&frequencyKnobLookAndFeel);
	lpRightSlider_.setLookAndFeel(&frequencyKnobLookAndFeel);
	hpRightSlider_.setLookAndFeel(&frequencyKnobLookAndFeel);

	lpLeftQSlider_.setLookAndFeel(&resonanceKnobLookAndFeel);
	hpLeftQSlider_.setLookAndFeel(&resonanceKnobLookAndFeel);
	lpRightQSlider_.setLookAndFeel(&resonanceKnobLookAndFeel);
	hpRightQSlider_.setLookAndFeel(&resonanceKnobLookAndFeel);


    setSize (470, 340);


	startTimer(50);
}

StereoFilterAudioProcessorEditor ::~StereoFilterAudioProcessorEditor ()
{
	
}

//==============================================================================
void StereoFilterAudioProcessorEditor ::paint (Graphics& g)
{
	Image background = ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize);
	g.drawImageAt(background, 0, 0);


}

void StereoFilterAudioProcessorEditor ::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	leftGroup_.setBounds(10, 10, 220, 300);
	lpLeftSlider_.setBounds(20, 50, 100, 100);
	hpLeftSlider_.setBounds(20, 200, 100, 100);
	lpLeftQSlider_.setBounds(135, 70, 80, 80);
	hpLeftQSlider_.setBounds(135, 220, 80, 80);

	rightGroup_.setBounds(240, 10, 220, 300);
    lpRightSlider_.setBounds(250, 50, 100, 100);
	hpRightSlider_.setBounds(250, 200, 100, 100);
	lpRightQSlider_.setBounds(365, 70, 80, 80);
	hpRightQSlider_.setBounds(365, 220, 80, 80);
}

void StereoFilterAudioProcessorEditor ::timerCallback()
{
	

	lpLeftSlider_.setValue(processor.lpLeftFreq_, dontSendNotification);
	hpLeftSlider_.setValue(processor.hpLeftFreq_, dontSendNotification);
	lpRightSlider_.setValue(processor.lpRightFreq_, dontSendNotification);
	hpRightSlider_.setValue(processor.hpRightFreq_, dontSendNotification);
	lpLeftQSlider_.setValue(processor.lpQLeftFreq_, dontSendNotification);
	hpLeftQSlider_.setValue(processor.hpQLeftFreq_, dontSendNotification);
	lpRightQSlider_.setValue(processor.lpQRightFreq_, dontSendNotification);
	hpRightQSlider_.setValue(processor.hpQRightFreq_, dontSendNotification);
	
}
void StereoFilterAudioProcessorEditor ::sliderValueChanged(Slider* sliderThatWasMoved)
{

	if (sliderThatWasMoved == &lpLeftSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kLPFreqLeftParam,
			(float)lpLeftSlider_.getValue());
	}
	else if (sliderThatWasMoved == &hpLeftSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kHPFreqLeftParam,
			(float)hpLeftSlider_.getValue());
	}
	else if (sliderThatWasMoved == &lpRightSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kLPFreqRightParam,
			(float)lpRightSlider_.getValue());
	}
	else if (sliderThatWasMoved == &hpRightSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kHPFreqRightParam,
			(float)hpRightSlider_.getValue());
	}
	else if (sliderThatWasMoved == &lpLeftQSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kLPQFreqLeftParam,
			(float)lpLeftQSlider_.getValue());
	}
	else if (sliderThatWasMoved == &hpLeftQSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kHPQFreqLeftParam,
			(float)hpLeftQSlider_.getValue());
	}
	else if (sliderThatWasMoved == &lpRightQSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kLPQFreqRightParam,
			(float)lpRightQSlider_.getValue());
	}
	else if (sliderThatWasMoved == &hpRightQSlider_)
	{
		processor.setParameterNotifyingHost(StereoFilterAudioProcessor::Parameters::kHPQFreqRightParam,
			(float)hpRightQSlider_.getValue());
	}

}