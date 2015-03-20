#include "grabber/CameraGrabber.h"

void CameraGrabber::setResultCallback( ICameraGrabberResultCallback callback )
{
   this->callback = callback;
}

void CameraGrabber::start()
{
   callback.getFrame(m_CameraGrabberFrame);

}
