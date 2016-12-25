#pragma once

#include <vector>
#include "image_buffer.h"

namespace Image_Function
{
	using namespace Bitmap_Image;

	template <typename TColorDepth>
	void ParameterValidation( const Template_Image::ImageTemplate < TColorDepth > & image1 )
	{
		if( image1.empty() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TColorDepth>
	void ParameterValidation( const Template_Image::ImageTemplate < TColorDepth > & image1,
							  const Template_Image::ImageTemplate < TColorDepth > & image2 )
	{
		if( image1.empty() || image2.empty() || image1.width() != image2.width() || image1.height() != image2.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TColorDepth>
	void ParameterValidation( const Template_Image::ImageTemplate < TColorDepth > & image1,
							  const Template_Image::ImageTemplate < TColorDepth > & image2,
							  const Template_Image::ImageTemplate < TColorDepth > & image3 )
	{
		if( image1.empty() || image2.empty() || image3.empty() || image1.width() != image2.width() || image1.height() != image2.height() ||
			image1.width() != image3.width() || image1.height() != image3.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TColorDepth>
	void ParameterValidation( const Template_Image::ImageTemplate < TColorDepth > & image, uint32_t startX, uint32_t startY,
							  uint32_t width, uint32_t height )
	{
		if( image.empty() || width == 0 || height == 0 || startX + width > image.width() || startY + height > image.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TColorDepth>
	void ParameterValidation( const Template_Image::ImageTemplate < TColorDepth > & image1, uint32_t startX1, uint32_t startY1,
							  const Template_Image::ImageTemplate < TColorDepth > & image2, uint32_t startX2, uint32_t startY2,
							  uint32_t width, uint32_t height )
	{
		if( image1.empty() || image2.empty() || width == 0 || height == 0 ||
			startX1 + width > image1.width() || startY1 + height > image1.height() ||
			startX2 + width > image2.width() || startY2 + height > image2.height() )
			throw imageException("Bad input parameters in image function");
	}

	template <typename TColorDepth>
	void ParameterValidation( const Template_Image::ImageTemplate < TColorDepth > & image1, uint32_t startX1, uint32_t startY1,
							  const Template_Image::ImageTemplate < TColorDepth > & image2, uint32_t startX2, uint32_t startY2,
							  const Template_Image::ImageTemplate < TColorDepth > & image3, uint32_t startX3, uint32_t startY3,
							  uint32_t width, uint32_t height )
	{
		if( image1.empty() || image2.empty() || image3.empty() || width == 0 || height == 0 ||
			startX1 + width > image1.width() || startY1 + height > image1.height() ||
			startX2 + width > image2.width() || startY2 + height > image2.height() ||
			startX3 + width > image3.width() || startY3 + height > image3.height() )
			throw imageException("Bad input parameters in image function");
	}


	Image AbsoluteDifference( const Image & in1, const Image & in2 );
	void  AbsoluteDifference( const Image & in1, const Image & in2, Image & out );
	Image AbsoluteDifference( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
							  uint32_t width, uint32_t height );
	void  AbsoluteDifference( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
							  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	void Accumulate( const Image & image, std::vector < uint32_t > & result );
	void Accumulate( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, std::vector < uint32_t > & result );

	Image BitwiseAnd( const Image & in1, const Image & in2 );
	void  BitwiseAnd( const Image & in1, const Image & in2, Image & out );
	Image BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height );
	void  BitwiseAnd( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image BitwiseOr( const Image & in1, const Image & in2 );
	void  BitwiseOr( const Image & in1, const Image & in2, Image & out );
	Image BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 uint32_t width, uint32_t height );
	void  BitwiseOr( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					 Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image BitwiseXor( const Image & in1, const Image & in2 );
	void  BitwiseXor( const Image & in1, const Image & in2, Image & out );
	Image BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  uint32_t width, uint32_t height );
	void  BitwiseXor( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	void Convert( const Image & in, ColorImage & out );
	void Convert( const ColorImage & in, Image & out );
	void Convert( const Image & in, uint32_t startXIn, uint32_t startYIn, ColorImage & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height );
	void Convert( const ColorImage & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height );

	void  Copy( const Image & in, Image & out );
	Image Copy( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Copy( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				uint32_t width, uint32_t height );

	Image ExtractChannel( const ColorImage & in, uint8_t channelId );
	Image ExtractChannel( const ColorImage & in, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint8_t channelId );
	void  ExtractChannel( const ColorImage & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut,
						  uint32_t startYOut, uint32_t width, uint32_t height, uint8_t channelId );

	void Fill( Image & image, uint8_t value );
	void Fill( Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, uint8_t value );

	// Make sure that input parameters such as input and output images are not same image!
	// horizontal flip: left-right --> right-left
	// vertical flip: top-bottom --> bottom-top
	Image Flip( const Image & in, bool horizontal, bool vertical );
	void  Flip( const Image & in, Image & out, bool horizontal, bool vertical );
	Image Flip( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height,
				bool horizontal, bool vertical);
	void  Flip( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				uint32_t width, uint32_t height, bool horizontal, bool vertical );

	// Gamma correction works by formula:
	// output = A * ((input / 255) ^ gamma) * 255, where A - multiplication, gamma - power base. Both values must be greater than 0
	// Usually people set A as 1
	Image GammaCorrection( const Image & in, double a, double gamma );
	void  GammaCorrection( const Image & in, Image & out, double a, double gamma );
	Image GammaCorrection( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, double a, double gamma );
	void  GammaCorrection( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
						   uint32_t width, uint32_t height, double a, double gamma );

	uint8_t GetPixel( const Image & image, uint32_t x, uint32_t y );

	uint8_t GetThreshold( const std::vector < uint32_t > & histogram );

	std::vector < uint32_t > Histogram( const Image & image );
	void                     Histogram( const Image & image, std::vector < uint32_t > & histogram );
	std::vector < uint32_t > Histogram( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height );
	void                     Histogram( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height,
										std::vector < uint32_t > & histogram );

	// Invert function is Bitwise NOT operation. But to make function name more user-friendly we named it like this
	Image Invert( const Image & in );
	void  Invert( const Image & in, Image & out );
	Image Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Invert( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
				  uint32_t width, uint32_t height );

	bool IsEqual( const Image & in1, const Image & in2 );
	bool IsEqual( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				  uint32_t width, uint32_t height );

	Image LookupTable( const Image & in, const std::vector < uint8_t > & table );
	void  LookupTable( const Image & in, Image & out, const std::vector < uint8_t > & table );
	Image LookupTable( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height,
					   const std::vector < uint8_t > & table );
	void  LookupTable( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					   uint32_t width, uint32_t height, const std::vector < uint8_t > & table );

	Image Maximum( const Image & in1, const Image & in2 );
	void  Maximum( const Image & in1, const Image & in2, Image & out );
	Image Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height );
	void  Maximum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	void Merge( const Image & in1, const Image & in2, const Image & in3, ColorImage & out );
	void Merge( const Image & in1, uint32_t startXIn1, uint32_t startYIn1, const Image & in2, uint32_t startXIn2, uint32_t startYIn2,
				const Image & in3, uint32_t startXIn3, uint32_t startYIn3,  ColorImage & out, uint32_t startXOut, uint32_t startYOut,
				uint32_t width, uint32_t height);

	Image Minimum( const Image & in1, const Image & in2 );
	void  Minimum( const Image & in1, const Image & in2, Image & out );
	Image Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   uint32_t width, uint32_t height );
	void  Minimum( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
				   Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	Image Normalize( const Image & in );
	void  Normalize( const Image & in, Image & out );
	Image Normalize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Normalize( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height );

	std::vector < uint32_t > ProjectionProfile( const Image & image, bool horizontal );
	void                     ProjectionProfile( const Image & image, bool horizontal, std::vector < uint32_t > & projection );
	std::vector < uint32_t > ProjectionProfile( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, bool horizontal );
	void                     ProjectionProfile( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height, bool horizontal,
												std::vector < uint32_t > & projection );

	// Image resizing (scaling) is based on nearest-neighbour interpolation method
	Image Resize( const Image & in, uint32_t widthOut, uint32_t heightOut );
	void  Resize( const Image & in, Image & out );
	Image Resize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t widthIn, uint32_t heightIn,
				  uint32_t widthOut, uint32_t heightOut );
	void  Resize( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t widthIn, uint32_t heightIn,
				  Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t widthOut, uint32_t heightOut );

	void Rotate( const Image & in, double centerXIn, double centerYIn, Image & out, double centerXOut, double centerYOut, double angle );

	void SetPixel( Image & image, uint32_t x, uint32_t y, uint8_t value );
	void SetPixel( Image & image, const std::vector < uint32_t > & X, const std::vector < uint32_t > & Y, uint8_t value );

	void Split( const ColorImage & in, Image & out1, Image & out2, Image & out3 );
	void Split( const ColorImage & in, uint32_t startXIn, uint32_t startYIn, Image & out1, uint32_t startXOut1, uint32_t startYOut1,
				Image & out2, uint32_t startXOut2, uint32_t startYOut2, Image & out3, uint32_t startXOut3, uint32_t startYOut3,
				uint32_t width, uint32_t height);

	Image Subtract( const Image & in1, const Image & in2 );
	void  Subtract( const Image & in1, const Image & in2, Image & out );
	Image Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					uint32_t width, uint32_t height );
	void  Subtract( const Image & in1, uint32_t startX1, uint32_t startY1, const Image & in2, uint32_t startX2, uint32_t startY2,
					Image & out, uint32_t startXOut, uint32_t startYOut, uint32_t width, uint32_t height );

	// Make sure that your image is not so big to do not have overloaded uint32_t value
	// For example not bigger than [4096 * 4096] for 32-bit application
	uint32_t Sum( const Image & image );
	uint32_t Sum( const Image & image, uint32_t x, int32_t y, uint32_t width, uint32_t height );

	// Thresholding works in such way:
		// if pixel intensity on input image is          less (  < ) than threshold then set pixel intensity on output image as 0
		// if pixel intensity on input image is equal or more ( >= ) than threshold then set pixel intensity on output image as 255
	Image Threshold( const Image & in, uint8_t threshold );
	void  Threshold( const Image & in, Image & out, uint8_t threshold );
	Image Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, uint8_t threshold );
	void  Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height, uint8_t threshold );

	// Thresholding works in such way:
		// if pixel intensity on input image is less ( < ) than minimum threshold or more ( > ) than maximum threshold
		// then      set pixel intensity on output image as 0
		// otherwise set pixel intensity on output image as 255
	Image Threshold( const Image & in, uint8_t minThreshold, uint8_t maxThreshold );
	void  Threshold( const Image & in, Image & out, uint8_t minThreshold, uint8_t maxThreshold );
	Image Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height, uint8_t minThreshold,
					 uint8_t maxThreshold );
	void  Threshold( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height, uint8_t minThreshold, uint8_t maxThreshold );

	// Swap columns and rows in input image. It is equivalent to 90 degree rotation
	// Output image (area) must be [height, width] compare to original [width, height]
	Image Transpose( const Image & in );
	void  Transpose( const Image & in, Image & out );
	Image Transpose( const Image & in, uint32_t startXIn, uint32_t startYIn, uint32_t width, uint32_t height );
	void  Transpose( const Image & in, uint32_t startXIn, uint32_t startYIn, Image & out, uint32_t startXOut, uint32_t startYOut,
					 uint32_t width, uint32_t height );
};
