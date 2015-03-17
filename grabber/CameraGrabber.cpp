

void CameraGrabber::setResultCallback( ICameraGrabberResultCallback callback )
{
   this.callback = callback;
}

void CameraGrabber::start()
{
   callback.getFrame( char *frame );
}
