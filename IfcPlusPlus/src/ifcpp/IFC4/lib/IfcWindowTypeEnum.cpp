/* Code generated by IfcQuery EXPRESS generator, www.ifcquery.com */

#include <sstream>
#include <limits>
#include <map>
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/model/IfcPPBasicTypes.h"
#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/IFC4/include/IfcWindowTypeEnum.h"

// TYPE IfcWindowTypeEnum = ENUMERATION OF	(WINDOW	,SKYLIGHT	,LIGHTDOME	,USERDEFINED	,NOTDEFINED);
IfcWindowTypeEnum::IfcWindowTypeEnum() {}
IfcWindowTypeEnum::~IfcWindowTypeEnum() {}
shared_ptr<IfcPPObject> IfcWindowTypeEnum::getDeepCopy( IfcPPCopyOptions& options )
{
	shared_ptr<IfcWindowTypeEnum> copy_self( new IfcWindowTypeEnum() );
	copy_self->m_enum = m_enum;
	return copy_self;
}
void IfcWindowTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
{
	if( is_select_type ) { stream << "IFCWINDOWTYPEENUM("; }
	switch( m_enum )
	{
		case ENUM_WINDOW:	stream << ".WINDOW."; break;
		case ENUM_SKYLIGHT:	stream << ".SKYLIGHT."; break;
		case ENUM_LIGHTDOME:	stream << ".LIGHTDOME."; break;
		case ENUM_USERDEFINED:	stream << ".USERDEFINED."; break;
		case ENUM_NOTDEFINED:	stream << ".NOTDEFINED."; break;
	}
	if( is_select_type ) { stream << ")"; }
}
const std::wstring IfcWindowTypeEnum::toString() const
{
	switch( m_enum ) 
	{
		case ENUM_WINDOW:	return L"WINDOW";
		case ENUM_SKYLIGHT:	return L"SKYLIGHT";
		case ENUM_LIGHTDOME:	return L"LIGHTDOME";
		case ENUM_USERDEFINED:	return L"USERDEFINED";
		case ENUM_NOTDEFINED:	return L"NOTDEFINED";
	}
	return L"";
}
shared_ptr<IfcWindowTypeEnum> IfcWindowTypeEnum::createObjectFromSTEP( const std::wstring& arg, const map_t<int,shared_ptr<IfcPPEntity> >& map )
{
	// read TYPE
	if( arg.compare( L"$" ) == 0 ) { return shared_ptr<IfcWindowTypeEnum>(); }
	else if( arg.compare( L"*" ) == 0 ) { return shared_ptr<IfcWindowTypeEnum>(); }
	shared_ptr<IfcWindowTypeEnum> type_object( new IfcWindowTypeEnum() );
	if( boost::iequals( arg, L".WINDOW." ) )
	{
		type_object->m_enum = IfcWindowTypeEnum::ENUM_WINDOW;
	}
	else if( boost::iequals( arg, L".SKYLIGHT." ) )
	{
		type_object->m_enum = IfcWindowTypeEnum::ENUM_SKYLIGHT;
	}
	else if( boost::iequals( arg, L".LIGHTDOME." ) )
	{
		type_object->m_enum = IfcWindowTypeEnum::ENUM_LIGHTDOME;
	}
	else if( boost::iequals( arg, L".USERDEFINED." ) )
	{
		type_object->m_enum = IfcWindowTypeEnum::ENUM_USERDEFINED;
	}
	else if( boost::iequals( arg, L".NOTDEFINED." ) )
	{
		type_object->m_enum = IfcWindowTypeEnum::ENUM_NOTDEFINED;
	}
	return type_object;
}