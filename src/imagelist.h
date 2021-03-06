#ifndef PICTURE_LIST_H_
#define PICTURE_LIST_H_
/*****************************************************************************
 * This file is part of Kvazaar HEVC encoder.
 *
 * Copyright (C) 2013-2014 Tampere University of Technology and others (see
 * COPYING file).
 *
 * Kvazaar is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation.
 *
 * Kvazaar is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Kvazaar.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

/*
 * \file
 * \brief List of images (for reference pictures)
 */

#include "image.h"
#include "cu.h"

/**
 * \brief Struct which contains array of picture structs
 */
typedef struct
{
  struct image* *images;          //!< \brief Pointer to array of picture pointers.
  cu_array* *cu_arrays;
  uint32_t size;       //!< \brief Array size.
  uint32_t used_size;
} image_list;

image_list * image_list_alloc(int size);
int image_list_resize(image_list *list, unsigned size);
int image_list_destroy(image_list *list);
int image_list_add(image_list *list, image *im, cu_array* cua);
int image_list_rem(image_list *list, unsigned n);

int image_list_copy_contents(image_list *target, image_list *source);

enum { REF_PIC_LIST_0 = 0, REF_PIC_LIST_1 = 1, REF_PIC_LIST_X = 100 };

#endif //PICTURE_LIST_H_
