/**
 * COPYRIGHT ⓒ 2017 Obigo Inc.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo Inc.,and may be
 * used and copied only in accordance with the terms of the
 * said agreement.
 *
 * Obigo Inc. assumes no responsibility or
 * liability for any errors or inaccuracies in this software,
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 * 
 * @section DESCRIPTION
 *
 * The serviceManager class.
 */

/**
 * Constructor
 *
*/

#include "service_manager.h"
#include <libwebsockets.h>

#include <stdio.h>

serviceManager::serviceManager(){
  //log (trace)
  printf("create serviceManager!\n");
}

/**
 * Destructor
 *
*/
serviceManager::~serviceManager() {
  //log (trace)
  printf("create serviceManager!\n");
}