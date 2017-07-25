#include <jni.h>
#include <string>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

extern "C"
{
void JNICALL Java_net_johnhany_opencv_1ndk_1camera_MainActivity_salt(JNIEnv *env, jobject instance,
                                                             jlong matAddrGray,
                                                             jint nbrElem) {

    Mat &mGr = *(Mat *) matAddrGray;

    for (int k = 0; k < nbrElem; k++) {
        int i = rand() % mGr.cols;
        int j = rand() % mGr.rows;
        mGr.at<uchar>(j, i) = 255;
    }
}
}

