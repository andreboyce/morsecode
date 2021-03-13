#pragma once

#include "AutoPtr.h"
#include <fmod/inc/fmod.hpp>
#include <fmod/inc/fmod_errors.h>
#include "ControlClass.h"

public ref class SoundClass
{
   public:

	  ControlClass^ controlClass;

	  System::Threading::Mutex^ m_mutex;

      FMOD::System *m_system;
	  FMOD::Sound  *m_DotSound, *m_DashSound, *m_SpaceSound;
	  FMOD::Channel *m_channel, * m_DotChannel, * m_DashChannel, * m_SpaceChannel;
	  FMOD::ChannelGroup *m_Group1, *m_MasterGroup;
	  unsigned int m_version;
	  int m_MaxChannels;
	  int m_defaultVolume;
	  float m_defaultFrequency;

	  System::String^ m_Message;
	  //bool m_bSoundPlaying;
	  bool m_bLoop;
	  bool m_bQuitThread;
	  bool m_bThreadLooping;
	  bool m_bPaused;

      SoundClass()
      {
	    m_bQuitThread  = false;
		m_channel      = nullptr;

		//m_DotChannel   = nullptr;
		//m_DashChannel  = nullptr;
		//m_SpaceChannel = nullptr;

		controlClass    = gcnew ControlClass();
		m_mutex           = gcnew System::Threading::Mutex();
		//m_bSoundPlaying = false;
		m_bLoop         = false;
		m_Message       = gcnew System::String( "" );
		m_version       = 0;
        FMOD_RESULT result;

		m_MaxChannels    = 100;
		m_defaultVolume  = 10;
		m_bThreadLooping = false;
		m_bPaused        = false;

		m_defaultFrequency = 0;
		
        // Create the main system object.
        FMOD::System *system = nullptr;
        result = FMOD::System_Create( &system );
        if( result != FMOD_OK )
        {
           HandleFmodError( result, "SoundClass" );
		}

		unsigned int version;
		result = system->getVersion(&version);
		if (result != FMOD_OK)
		{
			HandleFmodError(result, "SoundClass");
		}

		if (version < FMOD_VERSION)
		{
			HandleFmodError(result, "SoundClass FMOD_VERSION");
		}

		void* extradriverdata = 0;
		result = system->init(m_MaxChannels, FMOD_INIT_NORMAL, extradriverdata);   // Initialize FMOD.
        if( result != FMOD_OK )
        {
           HandleFmodError(result, "SoundClass");
		}

		m_system = system;

		LoadSounds();

		FMOD::ChannelGroup *Group1, *MasterGroup;
		result = m_system->createChannelGroup("Group 1", &Group1);
		if (result != FMOD_OK)
		{
			HandleFmodError(result, "SoundClass");
		}
		m_Group1 = Group1;

		result = system->getMasterChannelGroup(&MasterGroup);
		if (result != FMOD_OK)
		{
			HandleFmodError(result, "SoundClass");
		}
		m_MasterGroup = MasterGroup;

		if (m_channel != nullptr)
		{
			result = m_channel->setChannelGroup( m_Group1 );
			if (result != FMOD_OK)
			{
			   HandleFmodError(result, "SoundClass");
			}
		}
      }

      ~SoundClass()
      {
		 if (m_system != nullptr)
		    m_system->release();
      }

	  void HandleFmodError(FMOD_RESULT result)
	  {
		  System::String^ str = gcnew System::String(FMOD_ErrorString(result));
		  MessageBox::Show(str, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	  }

	  void HandleFmodError(FMOD_RESULT result, System::String^ details)
	  {
		  System::String^ str = gcnew System::String(FMOD_ErrorString(result));
		  MessageBox::Show(str, "Fmod Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	  }

	  void Alert( System::String^ message )
	  {
		  MessageBox::Show(message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	  }

	  void Alert( System::String^ result, System::String^ details)
	  {
		  MessageBox::Show(result + details, "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	  }

	  void SetMessage( System::String^ string )
	  {
		  m_Message = string;
	  }

      void LoadSounds()
      {
        FMOD_RESULT result;
        FMOD::Sound *DotSound, *DashSound, *SpaceSound;

		if (m_system != nullptr)
		{
			// FMOD_DEFAULT uses the defaults.
			// These are the same as FMOD_LOOP_OFF | FMOD_2D | FMOD_HARDWARE.
			result = m_system->createSound("sound/dot.ogg", FMOD_DEFAULT, 0, &DotSound);
			if (result != FMOD_OK)
			{
				HandleFmodError(result);
			}
			result = m_system->createSound("sound/dash.ogg", FMOD_DEFAULT, 0, &DashSound);
			if (result != FMOD_OK)
			{
				HandleFmodError(result);
			}
			result = m_system->createSound("sound/space.ogg", FMOD_DEFAULT, 0, &SpaceSound);
			if (result != FMOD_OK)
			{
				HandleFmodError(result);
			}
			m_DashSound  = DashSound;
			m_DotSound   = DotSound;
			m_SpaceSound = SpaceSound;
		}
      }

	  bool getPaused()
	  {
		  bool bIsPaused = false;
		  if (m_channel != nullptr)
		  {
			  FMOD_RESULT result;
			  if (m_Group1 != nullptr)
			  {
				  result = m_Group1->getPaused(&bIsPaused);
				  if (result != FMOD_OK)
				  {
					  HandleFmodError(result, "Stop");
				  }
			  }
		  }
		  return bIsPaused;
	  }

	  void Resume()
	  {
		  m_bPaused = false;
		  if (controlClass != nullptr)
		  {
			  controlClass->InvokeEnableControl(controlClass->buttonPause);
			  controlClass->InvokeDisableControl(controlClass->buttonStart);
			  controlClass->InvokeEnableControl(controlClass->buttonStop);
		  }
	  }

	  void Pause()
	  {
		 m_bPaused = true;
         if (controlClass != nullptr)
	     {
			controlClass->InvokeDisableControl(controlClass->buttonPause);
			controlClass->InvokeEnableControl(controlClass->buttonStart);
		    controlClass->InvokeEnableControl(controlClass->buttonStop);
		 }
	  }

      void Stop()
      {

		 if( m_channel != nullptr )
		 {

			if (m_Group1 != nullptr)
			{
				FMOD_RESULT result = m_Group1->stop();
				if (result != FMOD_OK)
				{
					HandleFmodError(result, "Stop");
				}
			}

		    m_bQuitThread         = true;
			m_bThreadLooping      = false;

			if (controlClass != nullptr)
			{
				controlClass->InvokeEnableControl(  controlClass->buttonStart);
				controlClass->InvokeDisableControl( controlClass->buttonPause);
				controlClass->InvokeDisableControl( controlClass->buttonStop);
				controlClass->InvokeSetCheckBoxValue(controlClass->checkBoxLoop, false );
			}
		 }
      }

	  void SetVolume( float volume )
	  {	 
		 if(m_MasterGroup!=nullptr)
		 {
			 FMOD_RESULT result = m_MasterGroup->setVolume(volume);
			 if (result != FMOD_OK)
			 {
				 HandleFmodError(result, "SetVolume");
			 }
		 }
	  }

	  void Play()
	  {
		  if (controlClass != nullptr)
		  {
	         controlClass->InvokeEnableControl( controlClass->buttonPause );
		  }
	  }

	  float GetFrequency()
	  {
		 float frequency = 0;

		 if(m_channel != nullptr )
		 {
			 FMOD_RESULT result = m_channel->getFrequency(&frequency);
			 if (result != FMOD_OK)
			 {
				 HandleFmodError(result, "GetFrequency");
			 }
		 }
	     return frequency;
	  }

	  void SetFrequency( float frequency )
	  {
		 if( m_channel != nullptr )
	     {
		    FMOD_RESULT result = m_channel->setFrequency( frequency );
            if( result != FMOD_OK )
            {
               HandleFmodError( result );
			}

			m_DotSound->setDefaults(   frequency, 0 );
			m_DashSound->setDefaults(  frequency, 1 );
			m_SpaceSound->setDefaults( frequency, 2 );

			if (controlClass != nullptr)
			{
				controlClass->InvokeSetNumericUpDownValue(controlClass->numericUpDownFrequency, (int)frequency);
			}
		 }
	  }

	  void PlayDotOrDash( int index )
	  {

		if( m_bQuitThread )
		   return;

	    FMOD::Channel *channel = nullptr;
		FMOD::Sound *Sound = nullptr;
	    FMOD_RESULT result;

		if( m_channel != nullptr )
		{
		   channel = m_channel;
		}

		   if(m_Message!=nullptr)
		   {
			   if (index < m_Message->Length)
			   {
				   if (m_Message[index] == '.')
				   {
					   if(m_system != nullptr)
					   {
						   //if (channel != nullptr)
						   //{
							   result = m_system->playSound(m_DotSound, m_Group1, false, &channel);
							   if (result != FMOD_OK)
							   {
								   HandleFmodError(result, "PlayDotOrDash");
							   }
							   m_DotChannel = channel;
						   //}
					   }
				   }
				   else if (m_Message[index] == '-')
				   {
					   if (m_system != nullptr)
					   {
						   //if (channel != nullptr)
						   //{
							   result = m_system->playSound(m_DashSound, m_Group1, false, &channel);
							   if (result != FMOD_OK)
							   {
								   HandleFmodError(result, "PlayDotOrDash");
							   }
							   m_DashChannel = channel;
							//}
					   }
				   }
				   else if (m_Message[index] == ' ')
				   {
					   if (m_system != nullptr)
					   {
						   //if (channel != nullptr)
						   //{
							   result = m_system->playSound(m_SpaceSound, m_Group1, false, &channel);
							   if (result != FMOD_OK)
							   {
								   HandleFmodError(result, "PlayDotOrDash");
							   }
							   m_SpaceChannel = channel;
						   //}
					   }
				   }
				   
				   if(channel != nullptr)
				   {
					   m_channel = channel;
					   if(m_defaultFrequency == 0)
					   {
						   m_defaultFrequency = GetFrequency();
						   if (controlClass != nullptr)
						   {
							   controlClass->InvokeSetNumericUpDownValue(controlClass->numericUpDownFrequency, (int)m_defaultFrequency);
						   }
					   }
				   }

				   if(controlClass!=nullptr)
				   {
					   controlClass->InvokeSelectText(controlClass->richTextBoxMCode, index, 1);
					   //controlClass->InvokeSelect(controlClass->richTextBoxMCode);
				   }
			   }
		   }
	  }

      void ThreadProc( void )
	  {
		 m_bThreadLooping = true;

		 int index = 0;
		 FMOD_RESULT result = FMOD_OK;

		 do
		 {
			if( m_bQuitThread )
			   break;

			if( m_bPaused == true )
			{
			   System::Threading::Thread::Sleep( 50 );
			   continue;
			}

			if( index == 0 )
			{
			   PlayDotOrDash( index );			   
			}
			else
			{
			   if( m_channel != nullptr )
			   {
			      bool bisplaying = false;

				  result = m_channel->isPlaying(&bisplaying);
				  if (result != FMOD_OK)
				  {
					HandleFmodError(result, "ThreadProc");
				  }
				  
			      bool bisPaused;

				  if (m_channel != nullptr)
				  {
					  if (m_Group1 != nullptr)
					  {
						  result = m_Group1->getPaused(&bisPaused);
						  if (result != FMOD_OK)
						  {
							  HandleFmodError(result, "Stop");
						  }
					  }
				  }

			      if( !bisplaying && !bisPaused )
			      {
			         PlayDotOrDash( index );
			      }
			      else
			      {
		             //System::Threading::Thread::Sleep( 50 );
			         if( m_bQuitThread )
			            break;
				     continue;
			      }
			   }

		       if( m_bQuitThread )
			      break;
			}

			index++;
			if(m_Message!=nullptr)
			{
				if (index >= m_Message->Length)
				{
					if (m_bLoop == true)
					{
						index = 0;
					}
					else
					{
						//m_bSoundPlaying = false;
						m_bThreadLooping = false;
					}
				}
			}
			if (m_system != nullptr)
			{
				int channelsplaying = 0;
				result = m_system->getChannelsPlaying(&channelsplaying, nullptr);
				if (result != FMOD_OK)
				{
					HandleFmodError(result, "ThreadProc");
				}
				result = m_system->update();
				if (result != FMOD_OK)
				{
					HandleFmodError(result, "ThreadProc");
				}
				if (controlClass != nullptr)
				{
					controlClass->InvokeSetNumericUpDownValue(controlClass->numericUpDownChannels, (int)channelsplaying);
				}
			}
		 }
		 while( m_bThreadLooping );

		 m_bPaused = false;

		 if (controlClass != nullptr)
		 {
			 if (controlClass->buttonStart != nullptr)
			 {
				 controlClass->InvokeEnableControl(controlClass->buttonStart);
				 controlClass->InvokeDisableControl(controlClass->buttonPause);
				 controlClass->InvokeDisableControl(controlClass->buttonStop);
			 }
		 }

		 /*
		 if (m_Group1 != nullptr)
		 {
			 result = m_Group1->release();
			 if (result != FMOD_OK)
			 {
				 HandleFmodError(result, "PlayDotOrDash");
			 }
		 }
		 */


		 return;		 
	  }
};
