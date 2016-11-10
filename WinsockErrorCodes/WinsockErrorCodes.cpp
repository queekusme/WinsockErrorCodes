// Copyright 2016 Annabelle Kennedy
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http ://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "WinsockErrorCodes.h"

#include <AtlBase.h>
#include <winerror.h>

namespace WSEC {
	ErrorCode getWinsockErrorCode(unsigned int providedErrorCode) {
		switch (providedErrorCode) {
		case WSAEINTR: return{ WSAEINTR, "WSAEINTR", "Interrupted function call", getFormattedDescription(WSAEINTR) };
		case WSAEBADF: return{ WSAEBADF, "WSAEBADF", "File handle is not valid", getFormattedDescription(WSAEINTR) };
		case WSAEACCES: return{ WSAEACCES, "WSAEACCES", "Permission denied", getFormattedDescription(WSAEINTR) };
		case WSAEFAULT: return{ WSAEFAULT, "WSAEFAULT", "Bad address", getFormattedDescription(WSAEINTR) };
		case WSAEINVAL: return{ WSAEINVAL, "WSAEINVAL", "Invalid argument", getFormattedDescription(WSAEINTR) };
		case WSAEMFILE: return{ WSAEMFILE, "WSAEMFILE", "Too many open files", getFormattedDescription(WSAEINTR) };
		case WSAEINPROGRESS: return{ WSAEINPROGRESS, "WSAEINPROGRESS", "Operation now in progress", getFormattedDescription(WSAEINTR) };
		case WSAEALREADY: return{ WSAEALREADY, "WSAEALREADY", "Operation already in progress", getFormattedDescription(WSAEINTR) };
		case WSAENOTSOCK: return{ WSAENOTSOCK, "WSAENOTSOCK", "Socket operation on nonsocket", getFormattedDescription(WSAEINTR) };
		case WSAEDESTADDRREQ: return{ WSAEDESTADDRREQ, "WSAEDESTADDRREQ", "Destination address required", getFormattedDescription(WSAEINTR) };
		case WSAEMSGSIZE: return{ WSAEMSGSIZE, "WSAEMSGSIZE", "Message too long", getFormattedDescription(WSAEINTR) };
		case WSAEPROTOTYPE: return{ WSAEPROTOTYPE, "WSAEPROTOTYPE", "Protocol wrong type for socket", getFormattedDescription(WSAEINTR) };
		case WSAENOPROTOOPT: return{ WSAENOPROTOOPT, "WSAENOPROTOOPT", "Bad protocol option", getFormattedDescription(WSAEINTR) };
		case WSAESOCKTNOSUPPORT: return{ WSAESOCKTNOSUPPORT, "WSAESOCKTNOSUPPORT", "Socket type not supported", getFormattedDescription(WSAEINTR) };
		case WSAEOPNOTSUPP: return{ WSAEOPNOTSUPP, "WSAEOPNOTSUPP", "Operation not supported", getFormattedDescription(WSAEINTR) };
		case WSAEPFNOSUPPORT: return{ WSAEPFNOSUPPORT, "WSAEPFNOSUPPORT", "Protocol family not supported.", getFormattedDescription(WSAEINTR) };
		case WSAEAFNOSUPPORT: return{ WSAEAFNOSUPPORT, "WSAEAFNOSUPPORT", "Address family not supported by protocol family", getFormattedDescription(WSAEINTR) };
		case WSAEADDRINUSE: return{ WSAEADDRINUSE, "WSAEADDRINUSE", "Address already in use", getFormattedDescription(WSAEINTR) };
		case WSAEADDRNOTAVAIL: return{ WSAEADDRNOTAVAIL, "WSAEADDRNOTAVAIL", "Cannot assign requested address", getFormattedDescription(WSAEINTR) };
		case WSAENETDOWN: return{ WSAENETDOWN, "WSAENETDOWN", "Network is down", getFormattedDescription(WSAEINTR) };
		case WSAENETUNREACH: return{ WSAENETUNREACH, "WSAENETUNREACH", "Network is unreachable", getFormattedDescription(WSAEINTR) };
		case WSAENETRESET: return{ WSAENETRESET, "WSAENETRESET", "Network dropped connection on reset", getFormattedDescription(WSAEINTR) };
		case WSAECONNABORTED: return{ WSAECONNABORTED, "WSAECONNABORTED", "Software caused connection abort", getFormattedDescription(WSAEINTR) };
		case WSAECONNRESET: return{ WSAECONNRESET, "WSAECONNRESET", "Connection reset by peer", getFormattedDescription(WSAEINTR) };
		case WSAENOBUFS: return{ WSAENOBUFS, "WSAENOBUFS", "No buffer space available", getFormattedDescription(WSAEINTR) };
		case WSAEISCONN: return{ WSAEISCONN, "WSAEISCONN", "Socket is already connected", getFormattedDescription(WSAEINTR) };
		case WSAENOTCONN: return{ WSAENOTCONN, "WSAENOTCONN", "Socket is not connected", getFormattedDescription(WSAEINTR) };
		case WSAESHUTDOWN: return{ WSAESHUTDOWN, "WSAESHUTDOWN", "Cannot send after socket shutdown.", getFormattedDescription(WSAEINTR) };
		case WSAETOOMANYREFS: return{ WSAETOOMANYREFS, "WSAETOOMANYREFS", "Too many references", getFormattedDescription(WSAEINTR) };
		case WSAETIMEDOUT: return{ WSAETIMEDOUT, "WSAETIMEDOUT", "Connection timed out", getFormattedDescription(WSAEINTR) };
		case WSAECONNREFUSED: return{ WSAECONNREFUSED, "WSAECONNREFUSED", "Connection refused", getFormattedDescription(WSAEINTR) };
		case WSAELOOP: return{ WSAELOOP, "WSAELOOP", "Cannot translate name", getFormattedDescription(WSAEINTR) };
		case WSAENAMETOOLONG: return{ WSAENAMETOOLONG, "WSAENAMETOOLONG", "Name too long", getFormattedDescription(WSAEINTR) };
		case WSAEHOSTDOWN: return{ WSAEHOSTDOWN, "WSAEHOSTDOWN", "Host is down", getFormattedDescription(WSAEINTR) };
		case WSAEHOSTUNREACH: return{ WSAEHOSTUNREACH, "WSAEHOSTUNREACH", "No route to host", getFormattedDescription(WSAEINTR) };
		case WSAENOTEMPTY: return{ WSAENOTEMPTY, "WSAENOTEMPTY", "Directory not empty", getFormattedDescription(WSAEINTR) };
		case WSAEPROCLIM: return{ WSAEPROCLIM, "WSAEPROCLIM", "Too many processes", getFormattedDescription(WSAEINTR) };
		case WSAEUSERS: return{ WSAEUSERS, "WSAEUSERS", "User quota exceeded", getFormattedDescription(WSAEINTR) };
		case WSAEDQUOT: return{ WSAEDQUOT, "WSAEDQUOT", "Disk quota exceeded", getFormattedDescription(WSAEINTR) };
		case WSAESTALE: return{ WSAESTALE, "WSAESTALE", "Stale file handle reference", getFormattedDescription(WSAEINTR) };
		case WSAEREMOTE: return{ WSAEREMOTE, "WSAEREMOTE", "Item is remote", getFormattedDescription(WSAEINTR) };
		case WSASYSNOTREADY: return{ WSASYSNOTREADY, "WSASYSNOTREADY", "Network subsystem is unavailable", getFormattedDescription(WSAEINTR) };
		case WSAVERNOTSUPPORTED: return{ WSAVERNOTSUPPORTED, "WSAVERNOTSUPPORTED", "Winsock.dll version out of range", getFormattedDescription(WSAEINTR) };
		case WSANOTINITIALISED: return{ WSANOTINITIALISED, "WSANOTINITIALISED", "Successful WSAStartup not yet performed.", getFormattedDescription(WSAEINTR) };
		case WSAEDISCON: return{ WSAEDISCON, "WSAEDISCON", "Graceful shutdown in progress.", getFormattedDescription(WSAEINTR) };
		case WSAENOMORE: return{ WSAENOMORE, "WSAENOMORE", "No more results", getFormattedDescription(WSAEINTR) };
		case WSAECANCELLED: return{ WSAECANCELLED, "WSAECANCELLED", "Call has been canceled", getFormattedDescription(WSAEINTR) };
		case WSAEINVALIDPROCTABLE: return{ WSAEINVALIDPROCTABLE, "WSAEINVALIDPROCTABLE", "Procedure call table is invalid", getFormattedDescription(WSAEINTR) };
		case WSAEINVALIDPROVIDER: return{ WSAEINVALIDPROVIDER, "WSAEINVALIDPROVIDER", "Service provider is invalid", getFormattedDescription(WSAEINTR) };
		case WSAEPROVIDERFAILEDINIT: return{ WSAEPROVIDERFAILEDINIT, "WSAEPROVIDERFAILEDINIT", "Service provider failed to initialize", getFormattedDescription(WSAEINTR) };
		case WSASYSCALLFAILURE: return{ WSASYSCALLFAILURE, "WSASYSCALLFAILURE", "System call failure", getFormattedDescription(WSAEINTR) };
		case WSASERVICE_NOT_FOUND: return{ WSASERVICE_NOT_FOUND, "WSASERVICE_NOT_FOUND", "Service not found", getFormattedDescription(WSAEINTR) };
		case WSATYPE_NOT_FOUND: return{ WSATYPE_NOT_FOUND, "WSATYPE_NOT_FOUND", "Class type not found", getFormattedDescription(WSAEINTR) };
		case WSA_E_NO_MORE: return{ WSA_E_NO_MORE, "WSA_E_NO_MORE", "No more results", getFormattedDescription(WSAEINTR) };
		case WSA_E_CANCELLED: return{ WSA_E_CANCELLED, "WSA_E_CANCELLED", "Call was canceled", getFormattedDescription(WSAEINTR) };
		case WSAEREFUSED: return{ WSAEREFUSED, "WSAEREFUSED", "Database query was refused", getFormattedDescription(WSAEINTR) };
		case WSAHOST_NOT_FOUND: return{ WSAHOST_NOT_FOUND, "WSAHOST_NOT_FOUND", "Host not found", getFormattedDescription(WSAEINTR) };
		case WSATRY_AGAIN: return{ WSATRY_AGAIN, "WSATRY_AGAIN", "Nonauthoritative host not found", getFormattedDescription(WSAEINTR) };
		case WSANO_RECOVERY: return{ WSANO_RECOVERY, "WSANO_RECOVERY", "This is a nonrecoverable error", getFormattedDescription(WSAEINTR) };
		case WSANO_DATA: return{ WSANO_DATA, "WSANO_DATA", "Valid name, no data record of requested type", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_RECEIVERS: return{ WSA_QOS_RECEIVERS, "WSA_QOS_RECEIVERS", "QoS receivers", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_SENDERS: return{ WSA_QOS_SENDERS, "WSA_QOS_SENDERS", "QoS senders", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_NO_SENDERS: return{ WSA_QOS_NO_SENDERS, "WSA_QOS_NO_SENDERS", "No QoS senders", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_NO_RECEIVERS: return{ WSA_QOS_NO_RECEIVERS, "WSA_QOS_NO_RECEIVERS", "QoS no receivers", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_REQUEST_CONFIRMED: return{ WSA_QOS_REQUEST_CONFIRMED, "WSA_QOS_REQUEST_CONFIRMED", "QoS request confirmed", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_ADMISSION_FAILURE: return{ WSA_QOS_ADMISSION_FAILURE, "WSA_QOS_ADMISSION_FAILURE", "QoS admission error", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_POLICY_FAILURE: return{ WSA_QOS_POLICY_FAILURE, "WSA_QOS_POLICY_FAILURE", "QoS policy failure", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_BAD_STYLE: return{ WSA_QOS_BAD_STYLE, "WSA_QOS_BAD_STYLE", "QoS bad style", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_BAD_OBJECT: return{ WSA_QOS_BAD_OBJECT, "WSA_QOS_BAD_OBJECT", "QoS bad object", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_TRAFFIC_CTRL_ERROR: return{ WSA_QOS_TRAFFIC_CTRL_ERROR, "WSA_QOS_TRAFFIC_CTRL_ERROR", "QoS traffic control error", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_GENERIC_ERROR: return{ WSA_QOS_GENERIC_ERROR, "WSA_QOS_GENERIC_ERROR", "QoS generic error", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_ESERVICETYPE: return{ WSA_QOS_ESERVICETYPE, "WSA_QOS_ESERVICETYPE", "QoS service type error", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EFLOWSPEC: return{ WSA_QOS_EFLOWSPEC, "WSA_QOS_EFLOWSPEC", "QoS flowspec error", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EPROVSPECBUF: return{ WSA_QOS_EPROVSPECBUF, "WSA_QOS_EPROVSPECBUF", "Invalid QoS provider buffer", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EFILTERSTYLE: return{ WSA_QOS_EFILTERSTYLE, "WSA_QOS_EFILTERSTYLE", "Invalid QoS filter style", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EFILTERTYPE: return{ WSA_QOS_EFILTERTYPE, "WSA_QOS_EFILTERTYPE", "Invalid QoS filter type", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EFILTERCOUNT: return{ WSA_QOS_EFILTERCOUNT, "WSA_QOS_EFILTERCOUNT", "Incorrect QoS filter count", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EOBJLENGTH: return{ WSA_QOS_EOBJLENGTH, "WSA_QOS_EOBJLENGTH", "Invalid QoS object length", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EFLOWCOUNT: return{ WSA_QOS_EFLOWCOUNT, "WSA_QOS_EFLOWCOUNT", "Incorrect QoS flow count", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EUNKOWNPSOBJ: return{ WSA_QOS_EUNKOWNPSOBJ, "WSA_QOS_EUNKOWNPSOBJ", "Unrecognized QoS object", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EPOLICYOBJ: return{ WSA_QOS_EPOLICYOBJ, "WSA_QOS_EPOLICYOBJ", "Invalid QoS policy object", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EFLOWDESC: return{ WSA_QOS_EFLOWDESC, "WSA_QOS_EFLOWDESC", "Invalid QoS flow descriptor", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EPSFLOWSPEC: return{ WSA_QOS_EPSFLOWSPEC, "WSA_QOS_EPSFLOWSPEC", "Invalid QoS provider-specific flowspec", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_EPSFILTERSPEC: return{ WSA_QOS_EPSFILTERSPEC, "WSA_QOS_EPSFILTERSPEC", "Invalid QoS provider-specific filterspec", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_ESDMODEOBJ: return{ WSA_QOS_ESDMODEOBJ, "WSA_QOS_ESDMODEOBJ", "Invalid QoS shape discard mode object", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_ESHAPERATEOBJ: return{ WSA_QOS_ESHAPERATEOBJ, "WSA_QOS_ESHAPERATEOBJ", "Invalid QoS shaping rate object", getFormattedDescription(WSAEINTR) };
		case WSA_QOS_RESERVED_PETYPE: return{ WSA_QOS_RESERVED_PETYPE, "WSA_QOS_RESERVED_PETYPE", "Reserved policy QoS element type", getFormattedDescription(WSAEINTR) };
		default: return{ -1, "UNKNOWN", "Unknown Error", "Error not defined!" };
		}
	}


	std::string getFormattedDescription(unsigned int providedErrorCode) {

		LPVOID lpMsgBuf;
		DWORD bufLen = FormatMessage( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, (DWORD)providedErrorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR)&lpMsgBuf, 0, NULL);

		if (bufLen) {
			std::string result = CT2A((LPCTSTR)lpMsgBuf);
			LocalFree(lpMsgBuf);
			return result;
		}
		return std::string();
	}
}