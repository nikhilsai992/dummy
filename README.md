# dummy
* Signals and systems
  * Linear Convolution is a mathematical method to find the output of Linear Time Invarient(LTI) system when its input signal and impulse response is given .It is applicable for both continous and discrete-time signals. For a input discrete time signal x(n) and the impusle response h(n) the linear convolution of the signal is represented as
y(n)= x(n) * h(n).

    Both input signal and impulse response need not to be of same length.The output response may or may not be equal to any of those two signals.The output signal obtained by the linear convolution may or may not be periodic.

  * Circular Convolution is also a mathematical method to ind the output of Linear Time Invarient(LTI) system when its input signal and impulse response is given. It is also applicable for both continous and discrete-time signals.For circular convolution, both the inputs x(n) and h(n) must be periodic which gives a periodic output.
   The number of samples in input signal and impulse response must be same.  The output of a circular convolution signal has same number of samples as of the inputs. In case of unequal number of samples we use a zero padding method to make sure both the inputs have same number of samples.
   
  * Cross Correlation is a measure of similarity of two signals.Let an input signal x(n) and the impulse response h(n), the cross correlation of these two signals y(n) is x(n)* h(-n).Cross correlation is used in pattern detection and signal detection.
 
  * Auto Correlation  is a measure of similarity of signal with itself.It is a correlation of a signal with the time shifted version of itself.Let an input signal x(n),the auto correlation of this signal is y(n)= x(n)* x(-n).
