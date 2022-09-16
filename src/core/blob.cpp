//
// Copyright (C) 2004-2008 Maciej Sobczak, Stephen Hutton
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//

#define SOCI_SOURCE
#include "soci/blob.h"
#include "soci/session.h"

#include <cstddef>

using namespace soci;

blob::blob(session & s)
{
    backEnd_ = s.make_blob_backend();
}

blob::~blob()
{
    delete backEnd_;
}

#ifdef SOCI_HAVE_CXX11

blob::blob(blob &&other)
{
    *this = std::move(other);
}

blob &blob::operator=(blob &&other)
{
    backEnd_ = std::move(other.backEnd_);

    // Explicitly null other.backEnd_ to avoid double-free
    other.backEnd_ = NULL;

    return *this;
}

#endif

std::size_t blob::get_len()
{
    return backEnd_->get_len();
}

std::size_t blob::read(std::size_t offset, char *buf, std::size_t toRead)
{
    return backEnd_->read(offset, buf, toRead);
}

std::size_t blob::read_from_start(char * buf, std::size_t toRead,
    std::size_t offset)
{
    return backEnd_->read_from_start(buf, toRead, offset);
}

std::size_t blob::write(
    std::size_t offset, char const * buf, std::size_t toWrite)
{
    return backEnd_->write(offset, buf, toWrite);
}

std::size_t blob::write_from_start(const char * buf, std::size_t toWrite,
    std::size_t offset)
{
    return backEnd_->write_from_start(buf, toWrite, offset);
}

std::size_t blob::append(char const * buf, std::size_t toWrite)
{
    return backEnd_->append(buf, toWrite);
}

void blob::trim(std::size_t newLen)
{
    backEnd_->trim(newLen);
}
