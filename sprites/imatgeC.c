typedef struct imatgeC {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned char	 *pixel_data; // [width * height * bytes_per_pixel + 1]
}imatgeC;
