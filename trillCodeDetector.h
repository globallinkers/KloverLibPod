//
// Created by thkim on 2020-02-12.
//

#ifndef TRILLCODEDETECTOR_H
#define TRILLCODEDETECTOR_H

#define _CRT_SECURE_NO_WARNINGS

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "define.h"
#include <cstdlib>

using namespace cv;
using namespace std;

namespace tcd {
    typedef void (*logFcn)(string);

    class trillCodeDetector {
    public:
        trillCodeDetector(const Mat &src, logFcn pfcn, char *phoneModel);
		void initVariables();
        int findImageTag(int nPhone, int nTagType);
        string getTagTrillCode();

        Mat m_srcTagImageGrayPerspective;
		Mat m_srcTagImageColorPerspective;
    private:
        int m_nTrillCodeIndex; // Trillcode image를 해석한 data와 서버로 부터 받은 m_arrResource Trillcode data가 서로 동일한 경우의 m_arrResource Index 번호
        char m_strTrillCodeCompanyOfTag[TRILL_COMPANY_LENGTH_DECIMAL + 1];
        char m_strTrillCodeBrandOfTag[TRILL_BRAND_LENGTH_DECIMAL + 1];
        char m_strTrillCodeProductOfTag[TRILL_PRODUCT_LENGTH_DECIMAL + 1];
		int m_nTagType;
		int m_nPhoneType;
//        int m_nTagShape;  // 정사각형, 직사각형, 원형태그
        int m_nTagWidth;
        int m_nTagHeight;
        float m_fDx;
        float m_fDy;
        vector<cv::Rect> m_vRectHiddenCode;
        char m_arrResource[REGISTERED_TAG_NUMBER][TOTAL_RESOURCE_LENGTH + 1];
        void setHiddenCodePosition(int nTagShape);
        int detectTrill(int nTagShape, int nPhone);
        Mat m_srcTagImageColor;                // 태그 원본 컬러 이미지,     일반적으로 m_srcTagImageColorBackUp을 m_srcTagImageColor으로 복사한 다음 m_srcTagImageColor을 가지고 영상처리
        Mat m_srcTagImageGray;                // 태그 원본 그레이 이미지
        Mat m_srcTagImageColorBackUp;       // 태그 원본 컬러 이미지, 최초원본이미지를 읽어들인 다음 whiteBalance를 실행하고서 저장한 태그 원본 컬러 이미지

        int m_nThreshold;
        logFcn m_logfcn;
		char m_phoneModel[10];

//		unsigned int m_nDebugCnt;
		
        void logd(string fmt, ...);
		bool checkParityBit(const char *pData, int len);
		
		void getTagInformation();
		
		int checkBlackWhite();
		int detectTrillCode(int nThreshold);
		int findTagEdge(int nModeThreshold);

		void whiteBalance(Mat &in, Mat &out, float percent);
		int checkValidEdge();
		int findTrillCode();

    };
}

#endif //TRILLCODEDETECTOR_H
