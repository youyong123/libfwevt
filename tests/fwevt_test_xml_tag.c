/*
 * Library xml_tag type test program
 *
 * Copyright (C) 2011-2018, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "fwevt_test_libcerror.h"
#include "fwevt_test_libfwevt.h"
#include "fwevt_test_macros.h"
#include "fwevt_test_memory.h"
#include "fwevt_test_unused.h"

#include "../libfwevt/libfwevt_xml_tag.h"

#if defined( __GNUC__ ) && !defined( LIBFWEVT_DLL_IMPORT )

/* Tests the libfwevt_xml_tag_initialize function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_initialize(
     void )
{
	libcerror_error_t *error        = NULL;
	libfwevt_xml_tag_t *xml_tag     = NULL;
	int result                      = 0;

#if defined( HAVE_FWEVT_TEST_MEMORY )
	int number_of_malloc_fail_tests = 1;
	int number_of_memset_fail_tests = 1;
	int test_number                 = 0;
#endif

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = libfwevt_xml_tag_initialize(
	          NULL,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	xml_tag = (libfwevt_xml_tag_t *) 0x12345678UL;

	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	xml_tag = NULL;

#if defined( HAVE_FWEVT_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test libfwevt_xml_tag_initialize with malloc failing
		 */
		fwevt_test_malloc_attempts_before_fail = test_number;

		result = libfwevt_xml_tag_initialize(
		          &xml_tag,
		          &error );

		if( fwevt_test_malloc_attempts_before_fail != -1 )
		{
			fwevt_test_malloc_attempts_before_fail = -1;

			if( xml_tag != NULL )
			{
				libfwevt_xml_tag_free(
				 &xml_tag,
				 NULL );
			}
		}
		else
		{
			FWEVT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWEVT_TEST_ASSERT_IS_NULL(
			 "xml_tag",
			 xml_tag );

			FWEVT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test libfwevt_xml_tag_initialize with memset failing
		 */
		fwevt_test_memset_attempts_before_fail = test_number;

		result = libfwevt_xml_tag_initialize(
		          &xml_tag,
		          &error );

		if( fwevt_test_memset_attempts_before_fail != -1 )
		{
			fwevt_test_memset_attempts_before_fail = -1;

			if( xml_tag != NULL )
			{
				libfwevt_xml_tag_free(
				 &xml_tag,
				 NULL );
			}
		}
		else
		{
			FWEVT_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			FWEVT_TEST_ASSERT_IS_NULL(
			 "xml_tag",
			 xml_tag );

			FWEVT_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_FWEVT_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_free function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_free(
	          NULL,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_value function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_value(
     void )
{
	libcerror_error_t *error    = NULL;
	libfvalue_value_t *value    = 0;
	libfwevt_xml_tag_t *xml_tag = NULL;
	int result                  = 0;
	int value_is_set            = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_value(
	          xml_tag,
	          &value,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	value_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_value(
	          NULL,
	          &value,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( value_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_value(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf8_name_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf8_name_size(
     void )
{
	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	size_t utf8_name_size       = 0;
	int result                  = 0;
	int utf8_name_size_is_set   = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf8_name_size(
	          xml_tag,
	          &utf8_name_size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf8_name_size(
	          NULL,
	          &utf8_name_size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_name_size_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf8_name_size(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf8_name function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf8_name(
     void )
{
	uint8_t utf8_name[ 512 ];

	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	int result                  = 0;
	int utf8_name_is_set        = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf8_name(
	          xml_tag,
	          utf8_name,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_name_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf8_name(
	          NULL,
	          utf8_name,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_name_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf8_name(
		          xml_tag,
		          NULL,
		          512,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf8_name(
		          xml_tag,
		          utf8_name,
		          0,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf8_name(
		          xml_tag,
		          utf8_name,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf16_name_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf16_name_size(
     void )
{
	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	size_t utf16_name_size      = 0;
	int result                  = 0;
	int utf16_name_size_is_set  = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf16_name_size(
	          xml_tag,
	          &utf16_name_size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_name_size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf16_name_size(
	          NULL,
	          &utf16_name_size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_name_size_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf16_name_size(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf16_name function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf16_name(
     void )
{
	uint16_t utf16_name[ 512 ];

	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	int result                  = 0;
	int utf16_name_is_set       = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf16_name(
	          xml_tag,
	          utf16_name,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_name_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf16_name(
	          NULL,
	          utf16_name,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_name_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf16_name(
		          xml_tag,
		          NULL,
		          512,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf16_name(
		          xml_tag,
		          utf16_name,
		          0,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf16_name(
		          xml_tag,
		          utf16_name,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf8_value_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf8_value_size(
     void )
{
	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	size_t utf8_value_size      = 0;
	int result                  = 0;
	int utf8_value_size_is_set  = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf8_value_size(
	          xml_tag,
	          &utf8_value_size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_value_size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf8_value_size(
	          NULL,
	          &utf8_value_size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_value_size_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf8_value_size(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf8_value function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf8_value(
     void )
{
	uint8_t utf8_value[ 512 ];

	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	int result                  = 0;
	int utf8_value_is_set       = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf8_value(
	          xml_tag,
	          utf8_value,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_value_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf8_value(
	          NULL,
	          utf8_value,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_value_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf8_value(
		          xml_tag,
		          NULL,
		          512,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf8_value(
		          xml_tag,
		          utf8_value,
		          0,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf8_value(
		          xml_tag,
		          utf8_value,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf16_value_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf16_value_size(
     void )
{
	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	size_t utf16_value_size     = 0;
	int result                  = 0;
	int utf16_value_size_is_set = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf16_value_size(
	          xml_tag,
	          &utf16_value_size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_value_size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf16_value_size(
	          NULL,
	          &utf16_value_size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_value_size_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf16_value_size(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf16_value function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf16_value(
     void )
{
	uint16_t utf16_value[ 512 ];

	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	int result                  = 0;
	int utf16_value_is_set      = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf16_value(
	          xml_tag,
	          utf16_value,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_value_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf16_value(
	          NULL,
	          utf16_value,
	          512,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_value_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf16_value(
		          xml_tag,
		          NULL,
		          512,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf16_value(
		          xml_tag,
		          utf16_value,
		          0,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );

		result = libfwevt_xml_tag_get_utf16_value(
		          xml_tag,
		          utf16_value,
		          (size_t) SSIZE_MAX + 1,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

	        FWEVT_TEST_ASSERT_IS_NOT_NULL(
	         "error",
	         error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_number_of_attributes function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_number_of_attributes(
     void )
{
	libcerror_error_t *error        = NULL;
	libfwevt_xml_tag_t *xml_tag     = NULL;
	int number_of_attributes        = 0;
	int number_of_attributes_is_set = 0;
	int result                      = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_number_of_attributes(
	          xml_tag,
	          &number_of_attributes,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	number_of_attributes_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_number_of_attributes(
	          NULL,
	          &number_of_attributes,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( number_of_attributes_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_number_of_attributes(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_number_of_elements function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_number_of_elements(
     void )
{
	libcerror_error_t *error      = NULL;
	libfwevt_xml_tag_t *xml_tag   = NULL;
	int number_of_elements        = 0;
	int number_of_elements_is_set = 0;
	int result                    = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_number_of_elements(
	          xml_tag,
	          &number_of_elements,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	number_of_elements_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_number_of_elements(
	          NULL,
	          &number_of_elements,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( number_of_elements_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_number_of_elements(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_flags function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_flags(
     void )
{
	libcerror_error_t *error    = NULL;
	libfwevt_xml_tag_t *xml_tag = NULL;
	uint8_t flags               = 0;
	int flags_is_set            = 0;
	int result                  = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_flags(
	          xml_tag,
	          &flags,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	flags_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_flags(
	          NULL,
	          &flags,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( flags_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_flags(
		          xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf8_xml_value_string_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf8_xml_value_string_size(
     void )
{
	libcerror_error_t *error              = NULL;
	libfwevt_xml_tag_t *xml_tag           = NULL;
	size_t utf8_xml_value_string_size     = 0;
	int result                            = 0;
	int utf8_xml_value_string_size_is_set = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf8_xml_value_string_size(
	          (libfwevt_internal_xml_tag_t *) xml_tag,
	          &utf8_xml_value_string_size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf8_xml_value_string_size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf8_xml_value_string_size(
	          NULL,
	          &utf8_xml_value_string_size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf8_xml_value_string_size_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf8_xml_value_string_size(
		          (libfwevt_internal_xml_tag_t *) xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

/* Tests the libfwevt_xml_tag_get_utf16_xml_value_string_size function
 * Returns 1 if successful or 0 if not
 */
int fwevt_test_xml_tag_get_utf16_xml_value_string_size(
     void )
{
	libcerror_error_t *error               = NULL;
	libfwevt_xml_tag_t *xml_tag            = NULL;
	size_t utf16_xml_value_string_size     = 0;
	int result                             = 0;
	int utf16_xml_value_string_size_is_set = 0;

	/* Initialize test
	 */
	result = libfwevt_xml_tag_initialize(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test regular cases
	 */
	result = libfwevt_xml_tag_get_utf16_xml_value_string_size(
	          (libfwevt_internal_xml_tag_t *) xml_tag,
	          &utf16_xml_value_string_size,
	          &error );

	FWEVT_TEST_ASSERT_NOT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	utf16_xml_value_string_size_is_set = result;

	/* Test error cases
	 */
	result = libfwevt_xml_tag_get_utf16_xml_value_string_size(
	          NULL,
	          &utf16_xml_value_string_size,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	FWEVT_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	if( utf16_xml_value_string_size_is_set != 0 )
	{
		result = libfwevt_xml_tag_get_utf16_xml_value_string_size(
		          (libfwevt_internal_xml_tag_t *) xml_tag,
		          NULL,
		          &error );

		FWEVT_TEST_ASSERT_EQUAL_INT(
		 "result",
		 result,
		 -1 );

		FWEVT_TEST_ASSERT_IS_NOT_NULL(
		 "error",
		 error );

		libcerror_error_free(
		 &error );
	}
	/* Clean up
	 */
	result = libfwevt_xml_tag_free(
	          &xml_tag,
	          &error );

	FWEVT_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "xml_tag",
	 xml_tag );

	FWEVT_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( xml_tag != NULL )
	{
		libfwevt_xml_tag_free(
		 &xml_tag,
		 NULL );
	}
	return( 0 );
}

#endif /* #if defined( __GNUC__ ) && !defined( LIBFWEVT_DLL_IMPORT ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc FWEVT_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] FWEVT_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc FWEVT_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] FWEVT_TEST_ATTRIBUTE_UNUSED )
#endif
{
	FWEVT_TEST_UNREFERENCED_PARAMETER( argc )
	FWEVT_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ ) && !defined( LIBFWEVT_DLL_IMPORT )

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_initialize",
	 fwevt_test_xml_tag_initialize );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_free",
	 fwevt_test_xml_tag_free );

	/* TODO: add tests for libfwevt_xml_tag_set_type */

	/* TODO: add tests for libfwevt_xml_tag_set_name_data */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_value",
	 fwevt_test_xml_tag_get_value );

	/* TODO: add tests for libfwevt_xml_tag_set_value_type */

	/* TODO: add tests for libfwevt_xml_tag_set_value_format_flags */

	/* TODO: add tests for libfwevt_xml_tag_set_value_data */

	/* TODO: add tests for libfwevt_xml_tag_append_value_data */

	/* TODO: add tests for libfwevt_xml_tag_set_value_strings_array */

	/* TODO: add tests for libfwevt_xml_tag_append_attribute */

	/* TODO: add tests for libfwevt_xml_tag_append_element */

#ifdef TODO

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf8_name_size",
	 fwevt_test_xml_tag_get_utf8_name_size );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf8_name",
	 fwevt_test_xml_tag_get_utf8_name );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf16_name_size",
	 fwevt_test_xml_tag_get_utf16_name_size );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf16_name",
	 fwevt_test_xml_tag_get_utf16_name );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf8_value_size",
	 fwevt_test_xml_tag_get_utf8_value_size );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf8_value",
	 fwevt_test_xml_tag_get_utf8_value );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf16_value_size",
	 fwevt_test_xml_tag_get_utf16_value_size );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf16_value",
	 fwevt_test_xml_tag_get_utf16_value );

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_number_of_attributes",
	 fwevt_test_xml_tag_get_number_of_attributes );

	/* TODO: add tests for libfwevt_xml_tag_get_attribute_by_index */

	/* TODO: add tests for libfwevt_xml_tag_get_attribute_by_utf8_name */

	/* TODO: add tests for libfwevt_xml_tag_get_attribute_by_utf16_name */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_number_of_elements",
	 fwevt_test_xml_tag_get_number_of_elements );

	/* TODO: add tests for libfwevt_xml_tag_get_element_by_index */

	/* TODO: add tests for libfwevt_xml_tag_get_element_by_utf8_name */

	/* TODO: add tests for libfwevt_xml_tag_get_element_by_utf16_name */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_flags",
	 fwevt_test_xml_tag_get_flags );

	/* TODO: add tests for libfwevt_xml_tag_set_flags */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf8_xml_value_string_size",
	 fwevt_test_xml_tag_get_utf8_xml_value_string_size );

	/* TODO: add tests for libfwevt_xml_tag_get_utf8_xml_value_string_with_index */

	/* TODO: add tests for libfwevt_xml_tag_get_utf8_xml_string_size */

	/* TODO: add tests for libfwevt_xml_tag_get_utf8_xml_string_with_index */

	FWEVT_TEST_RUN(
	 "libfwevt_xml_tag_get_utf16_xml_value_string_size",
	 fwevt_test_xml_tag_get_utf16_xml_value_string_size );

	/* TODO: add tests for libfwevt_xml_tag_get_utf16_xml_value_string_with_index */

	/* TODO: add tests for libfwevt_xml_tag_get_utf16_xml_string_size */

	/* TODO: add tests for libfwevt_xml_tag_get_utf16_xml_string_with_index */

	/* TODO: add tests for libfwevt_xml_tag_debug_print_value_string */

	/* TODO: add tests for libfwevt_xml_tag_debug_print */

	/* TODO: add tests for libfwevt_xml_tag_name_debug_print */

	/* TODO: add tests for libfwevt_xml_tag_value_debug_print */

#endif /* TODO */

#endif /* #if defined( __GNUC__ ) && !defined( LIBFWEVT_DLL_IMPORT ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

