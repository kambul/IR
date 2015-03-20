
#ifndef ICAMERAGRABBERRESULTCALLBACK_H
#define ICAMERAGRABBERRESULTCALLBACK_H

class ICameraGrabberResultCallback
{
public:
   virtual void getFrame ( char *frame );
private:
    char* m_frame;
};

#endif


