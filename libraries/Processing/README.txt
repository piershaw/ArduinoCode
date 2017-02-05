THINGS TO DO (known issues and desired features):
	* fix portrait/landscape bug in the Processing generation app tool, it should be a change in the way the manifest file is generated
	* ADK uploader tool crashes Processing when you try to use it in Standard mode, we should detect that case and push a warning to the user
	* why does each sketch need a code directory?  Why can't they inherit from the main lib? If anyone can explain this to me, I will be the happiest man in the world
  * IMPORTANT: the tool compiles great for Android 2.3.4 devices (or compatible with the com.future.usb library, but not with the latest usb api. In other words, this will crash with your super cute tablet running Android 4.0. This is just a matter of modifying the way the manifest file is generated, if you have the time to take a look at it and solve it ... just make a pull request and we will bring it in!

	* Fix Processing connect() When you reset the Arduino by opening the serial monitor, you lose the connection. Only way to get it back is to re-install the Android app
	* Make "Your Company Name" the tool default company name

	* Fix Processing write() so that when you send an int, you get 0-255 on the Arduino side like you do with Serial. Iput in method signature that takes an int, but it still needs fixing.

	* Finish the API, make all methods return values like Serial library does (note write() does not currently. Note that most of this can probably be taken straight from Processing's Serial.java, which mostly manipulates an InputStream and an OutputStream)

UsbAccessory(PApplet p)			- Constructor
int available()				- returns number of bytes available in inputStream
boolean connect() 			- attempts USB connection
void disconnect() 			- disconnects the USB connection
boolean isConnected() 			- returns whether the connection is valid
char readChar() 			- returns next byte of inputStream as a char
int readBytes() 			- returns the number of bytes available to read
byte[] readBytesUntil(thisInt) 		- reads bytes from the inputStream until it encounters thisInt
String readString() 			- reads the contents of the inputStream as a String
String readStringUntil(thisInt)		-  reads the contents of the inputStream until it encounters thisInt, returns them as a String 
buffer(int count)			- buffers until bytes is received (stops usbEvent until then)
bufferUntil(int thisInt) 		- buffers until thisInt is received (stops usbEvent until then)
usbEvent(UsbAccessory thisAccessory) 	- generates an Event that the parent applet can react to
int last() 				- returns the last byte of inputStream
char lastChar() 			- returns the last byte of inputStream as a char
void write(int thisInt) 		- writes an int out the outputStream.  
						** Should convert it to a byte properly, so values 0-255 are received as such.
void write(byte thisByte) 		- writes a byte out the outputStream.
void write(String thisString) 		- writes a string out the outputStream
void clear() 				- clears the inputStream
void stop() 				- closes USB connection, disposes of the instance
String[] list() 			- lists all available USB Accessories

