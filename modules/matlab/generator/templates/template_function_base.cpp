/*
 * file:   {{fun.name}}.cpp
 * author: A trusty code generator
 * date:   {{time.strftime("%a, %d %b %Y %H:%M:%S", time.localtime())}}
 * 
 * This file was autogenerated, do not modify.
 * See LICENCE for full modification and redistribution details.
 * Copyright {{time.strftime("%Y", time.localtime())}} The OpenCV Foundation
 */
#include "mex.h"
#include "bridge.hpp"
#include <string>
#include <vector>
#include <exception>
#include <opencv2/core.hpp>
{% block includes %}
{% endblock %}

/* 
 * {{ fun.name }}
 * Gateway routine
 *   nlhs - number of return arguments
 *   plhs - pointers to return arguments
 *   nrhs - number of input arguments
 *   prhs - pointers to input arguments
 */
void mexFunction(int nlhs, mxArray* plhs[],
                 int nrhs, const mxArray* prhs[]) {

  {% block argcheck %}
  {% endblock %}

  {% block prebridge %}
  {% endblock %}

  // parse the inputs and outputs

  {% block postbridge %}
  {% endblock %}

  // call the opencv function
  // [out =] namespace.fun(src1, ..., srcn, dst1, ..., dstn, opt1, ..., optn);
  try {
    {{fun.name}}();
  } catch(cv::Exception& e) {
    mexErrMsgTxt(std::string("cv::exception caught: ").append(e.what()).c_str());
  } catch(std::exception& e) {
    mexErrMsgTxt(std::string("std::exception caught: ").append(e.what()).c_str());
  } catch(...) {
    mexErrMsgTxt("Uncaught exception occurred in {{fun.name}}");
  }
  {% block fcall %}
  {% endblock %}

  {% block postfun %}
  {% endblock %}

  {% block cleanup %}
  {% endblock %}
}
