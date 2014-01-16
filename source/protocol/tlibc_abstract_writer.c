#include "protocol/tlibc_abstract_writer.h"
#include "lib/tlibc_error_code.h"

void tlibc_abstract_writer_init(TLIBC_ABSTRACT_WRITER *self)
{
	self->write_struct_begin = NULL;
	self->write_struct_end = NULL;
	self->write_union_begin = NULL;
	self->write_union_end = NULL;
	self->write_enum_begin = NULL;
	self->write_enum_end = NULL;
	self->write_vector_begin = NULL;
	self->write_vector_end = NULL;
	self->write_field_begin = NULL;
	self->write_field_end = NULL;

	self->write_tint8 = NULL;
	self->write_tint16 = NULL;
	self->write_tint32 = NULL;
	self->write_tint64 = NULL;
	self->write_tuint8 = NULL;
	self->write_tuint16 = NULL;
	self->write_tuint32 = NULL;
	self->write_tuint64 = NULL;
	self->write_tchar = NULL;
	self->write_tdouble = NULL;

	self->write_enum_name = NULL;	
	self->write_string = NULL;

}

tint32 write_struct_begin(TLIBC_ABSTRACT_WRITER *self, const char *struct_name)
{
	if(self->write_struct_begin == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_struct_begin(self, struct_name);
}

tint32 write_struct_end(TLIBC_ABSTRACT_WRITER *self, const char *struct_name)
{
	if(self->write_struct_end == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_struct_end(self, struct_name);
}

tint32 write_union_begin(TLIBC_ABSTRACT_WRITER *self, const char *union_name)
{
	if(self->write_union_begin == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_union_begin(self, union_name);
}

tint32 write_union_end(TLIBC_ABSTRACT_WRITER *self, const char *union_name)
{
	if(self->write_union_end == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_union_end(self, union_name);
}


tint32 write_enum_begin(TLIBC_ABSTRACT_WRITER *self, const char *enum_name)
{
	if(self->write_enum_begin == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_enum_begin(self, enum_name);
}

tint32 write_enum_end(TLIBC_ABSTRACT_WRITER *self, const char *enum_name)
{
	if(self->write_enum_end == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_enum_end(self, enum_name);
}

tint32 write_vector_begin(TLIBC_ABSTRACT_WRITER *self)
{
	if(self->write_vector_begin == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_vector_begin(self);
}

tint32 write_vector_end(TLIBC_ABSTRACT_WRITER *self)
{
	if(self->write_vector_end == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_vector_end(self);
}

tint32 write_field_begin(TLIBC_ABSTRACT_WRITER *self, const char *var_name)
{
	if(self->write_field_begin == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_field_begin(self, var_name);
}

tint32 write_field_end(TLIBC_ABSTRACT_WRITER *self, const char *var_name)
{
	if(self->write_field_end == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_field_end(self, var_name);
}

tint32 write_tint8(TLIBC_ABSTRACT_WRITER *self, const tint8 *val)
{
	if(self->write_tint8 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tint8(self, val);
}

tint32 write_tint16(TLIBC_ABSTRACT_WRITER *self, const tint16 *val)
{
	if(self->write_tint16 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tint16(self, val);
}

tint32 write_tint32(TLIBC_ABSTRACT_WRITER *self, const tint32 *val)
{
	if(self->write_tint32 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tint32(self, val);
}

tint32 write_tint64(TLIBC_ABSTRACT_WRITER *self, const tint64 *val)
{
	if(self->write_tint64 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tint64(self, val);
}

tint32 write_tuint8(TLIBC_ABSTRACT_WRITER *self, const tuint8 *val)
{
	if(self->write_tuint8 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tuint8(self, val);
}

tint32 write_tuint16(TLIBC_ABSTRACT_WRITER *self, const tuint16 *val)
{
	if(self->write_tuint16 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tuint16(self, val);
}

tint32 write_tuint32(TLIBC_ABSTRACT_WRITER *self, const tuint32 *val)
{
	if(self->write_tuint32 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tuint32(self, val);
}

tint32 write_tuint64(TLIBC_ABSTRACT_WRITER *self, const tuint64 *val)
{
	if(self->write_tuint64 == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tuint64(self, val);
}

tint32 write_tchar(TLIBC_ABSTRACT_WRITER *self, const tchar *val)
{
	if(self->write_tchar == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tchar(self, val);
}

tint32 write_tdouble(TLIBC_ABSTRACT_WRITER *self, const tdouble *val)
{
	if(self->write_tdouble == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_tdouble(self, val);
}

tint32 write_enum_name(TLIBC_ABSTRACT_WRITER *self, const tchar *enum_name)
{
	if(self->write_enum_name == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_enum_name(self, enum_name);
}

tint32 write_tstring(TLIBC_ABSTRACT_WRITER *self, const tchar* str)
{
	if(self->write_string == NULL)
	{
		return E_TLIBC_NOERROR;
	}
	return self->write_string(self, str);
}
