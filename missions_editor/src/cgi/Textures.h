/****************************************************************************//*
 * Copyright (C) 2020 Marek M. Cel
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 ******************************************************************************/
#ifndef TEXTURES_H
#define TEXTURES_H

////////////////////////////////////////////////////////////////////////////////

#include <osg/Texture2D>

#include <editor/Singleton.h>

////////////////////////////////////////////////////////////////////////////////

/** Textures container class. */
class Textures : public Singleton< Textures >
{
    friend class Singleton< Textures >;

public:

    typedef std::vector< osg::ref_ptr<osg::Texture2D> > List;

    /** */
    static osg::Texture2D* get( std::string textureFile, float maxAnisotropy = 1.0f );

private:

    /**
     * You should use static function getInstance() due to get refernce
     * to Textures class instance.
     */
    Textures();

    /** Using this constructor is forbidden. */
    Textures( const Textures & ) : Singleton< Textures >() {}

public:

    /** Destructor. */
    virtual ~Textures();

private:

    List m_textures;                        ///<
    std::vector< std::string > m_fileNames; ///<
};

////////////////////////////////////////////////////////////////////////////////

#endif // TEXTURES_H
