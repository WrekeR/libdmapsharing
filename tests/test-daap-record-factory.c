/*
 * DAAPRecord factory class
 *
 * Copyright (C) 2008 W. Michael Petullo <mike@flyn.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "test-daap-record-factory.h"
#include "test-daap-record.h"

DMAPRecord *
test_daap_record_factory_create  (DMAPRecordFactory *factory, gpointer user_data)
{
	return DMAP_RECORD (test_daap_record_new ());
}

static void
test_daap_record_factory_init (TestDAAPRecordFactory *factory)
{
}

static void
test_daap_record_factory_class_init (TestDAAPRecordFactoryClass *klass)
{
}

static void
test_daap_record_factory_interface_init (gpointer iface, gpointer data)
{
	DMAPRecordFactoryInterface *factory = iface;

	g_assert (G_TYPE_FROM_INTERFACE (factory) == TYPE_DMAP_RECORD_FACTORY);

	factory->create = test_daap_record_factory_create;
}

G_DEFINE_TYPE_WITH_CODE (TestDAAPRecordFactory, test_daap_record_factory, G_TYPE_OBJECT, 
			 G_IMPLEMENT_INTERFACE (TYPE_DMAP_RECORD_FACTORY,
					        test_daap_record_factory_interface_init))

TestDAAPRecordFactory *
test_daap_record_factory_new (void)
{
	TestDAAPRecordFactory *factory;

	factory = TEST_DAAP_RECORD_FACTORY (g_object_new (TYPE_TEST_DAAP_RECORD_FACTORY, NULL));

	return factory;
}
