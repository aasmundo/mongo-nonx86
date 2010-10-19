/** @checksum.h */

/*    Copyright 2009 10gen Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#pragma once

namespace mongoutils {

    /**
     * this is a silly temporary implementation
     */
    inline int checksum( const char* x , int size ){
        int ck = 0;
        for ( int i=0; i<size; i++ )
            ck += ( (int)x[i] * ( i + 1 ) );
        return ck;
    }

    inline unsigned hashAPointer(void *v) {
        unsigned x = 0;
        unsigned char *p = (unsigned char *) &v;
        for( unsigned i = 0; i < sizeof(void*); i++ ) {
            x = x * 131 + p[i];
        }
        return x;
    }

}
