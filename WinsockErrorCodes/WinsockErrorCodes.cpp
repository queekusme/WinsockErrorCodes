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

#include <winsock.h>
#include <Windows.h>

ErrorCode getWinsockErrorCode(UINT providedErrorCode) {
	switch (providedErrorCode) {
	case SOCKET_ERROR: return{ SOCKET_ERROR, "SOCKET_ERROR", "Socket Error", "Generic Socket Error." };
	case WSAEINTR: return{ WSAEINTR, "WSAEINTR", "Interrupted function call", "A blocking operation was interrupted by a call to WSACancelBlockingCall." };
	case WSAEBADF: return{ WSAEBADF, "WSAEBADF", "File handle is not valid", "The file handle supplied is not valid." };
	case WSAEACCES: return{ WSAEACCES, "WSAEACCES", "Permission denied", "An attempt was made to access a socket in a way forbidden by its access permissions. An example is using a broadcast address for sendto without broadcast permission being set using setsockopt(SO_BROADCAST). Another possible reason for the WSAEACCES error is that when the bind function is called(on Windows NT 4.0 with SP4 and later), another application, service, or kernel mode driver is bound to the same address with exclusive access.Such exclusive access is a new feature of Windows NT 4.0 with SP4 and later, and is implemented by using the SO_EXCLUSIVEADDRUSE option." };
	case WSAEFAULT: return{ WSAEFAULT, "WSAEFAULT", "Bad address", "The system detected an invalid pointer address in attempting to use a pointer argument of a call. This error occurs if an application passes an invalid pointer value, or if the length of the buffer is too small. For instance, if the length of an argument, which is a sockaddr structure, is smaller than the sizeof(sockaddr)." };
	case WSAEINVAL: return{ WSAEINVAL, "WSAEINVAL", "Invalid argument", "Some invalid argument was supplied (for example, specifying an invalid level to the setsockopt function). In some instances, it also refers to the current state of the socket�for instance, calling accept on a socket that is not listening." };
	case WSAEMFILE: return{ WSAEMFILE, "WSAEMFILE", "Too many open files", "Too many open sockets. Each implementation may have a maximum number of socket handles available, either globally, per process, or per thread." };
	case WSAEWOULDBLOCK: return{ WSAEWOULDBLOCK, "WSAEWOULDBLOCK", "Resource temporarily unavailable", "This error is returned from operations on nonblocking sockets that cannot be completed immediately, for example recv when no data is queued to be read from the socket. It is a nonfatal error, and the operation should be retried later. It is normal for WSAEWOULDBLOCK to be reported as the result from calling connect on a nonblocking SOCK_STREAM socket, since some time must elapse for the connection to be established." };
	case WSAEINPROGRESS: return{ WSAEINPROGRESS, "WSAEINPROGRESS", "Operation now in progress", "A blocking operation is currently executing. Windows Sockets only allows a single blocking operation�per- task or thread�to be outstanding, and if any other function call is made (whether or not it references that or any other socket) the function fails with the WSAEINPROGRESS error." };
	case WSAEALREADY: return{ WSAEALREADY, "WSAEALREADY", "Operation already in progress", "An operation was attempted on a nonblocking socket with an operation already in progress�that is, calling connect a second time on a nonblocking socket that is already connecting, or canceling an asynchronous request (WSAAsyncGetXbyY) that has already been canceled or completed." };
	case WSAENOTSOCK: return{ WSAENOTSOCK, "WSAENOTSOCK", "Socket operation on nonsocket", "An operation was attempted on something that is not a socket. Either the socket handle parameter did not reference a valid socket, or for select, a member of an fd_set was not valid." };
	case WSAEDESTADDRREQ: return{ WSAEDESTADDRREQ, "WSAEDESTADDRREQ", "Destination address required", "A required address was omitted from an operation on a socket. For example, this error is returned if sendto is called with the remote address of ADDR_ANY." };
	case WSAEMSGSIZE: return{ WSAEMSGSIZE, "WSAEMSGSIZE", "Message too long", "A message sent on a datagram socket was larger than the internal message buffer or some other network limit, or the buffer used to receive a datagram was smaller than the datagram itself." };
	case WSAEPROTOTYPE: return{ WSAEPROTOTYPE, "WSAEPROTOTYPE", "Protocol wrong type for socket", "A protocol was specified in the socket function call that does not support the semantics of the socket type requested. For example, the ARPA Internet UDP protocol cannot be specified with a socket type of SOCK_STREAM." };
	case WSAENOPROTOOPT: return{ WSAENOPROTOOPT, "WSAENOPROTOOPT", "Bad protocol option", "An unknown, invalid or unsupported option or level was specified in a getsockopt or setsockopt call." };
	case WSAEPROTONOSUPPORT: return{ WSAEPROTONOSUPPORT, "WSAEPROTONOSUPPORT", "Protocol not supported", "The requested protocol has not been configured into the system, or no implementation for it exists. For example, a socket call requests a SOCK_DGRAM socket, but specifies a stream protocol." };
	case WSAESOCKTNOSUPPORT: return{ WSAESOCKTNOSUPPORT, "WSAESOCKTNOSUPPORT", "Socket type not supported", "The support for the specified socket type does not exist in this address family. For example, the optional type SOCK_RAW might be selected in a socket call, and the implementation does not support SOCK_RAW sockets at all." };
	case WSAEOPNOTSUPP: return{ WSAEOPNOTSUPP, "WSAEOPNOTSUPP", "Operation not supported", "The attempted operation is not supported for the type of object referenced. Usually this occurs when a socket descriptor to a socket that cannot support this operation is trying to accept a connection on a datagram socket." };
	case WSAEPFNOSUPPORT: return{ WSAEPFNOSUPPORT, "WSAEPFNOSUPPORT", "Protocol family not supported.", "The protocol family has not been configured into the system or no implementation for it exists. This message has a slightly different meaning from WSAEAFNOSUPPORT. However, it is interchangeable in most cases, and all Windows Sockets functions that return one of these messages also specify WSAEAFNOSUPPORT." };
	case WSAEAFNOSUPPORT: return{ WSAEAFNOSUPPORT, "WSAEAFNOSUPPORT", "Address family not supported by protocol family", "An address incompatible with the requested protocol was used. All sockets are created with an associated address family (that is, AF_INET for Internet Protocols) and a generic protocol type (that is, SOCK_STREAM). This error is returned if an incorrect protocol is explicitly requested in the socket call, or if an address of the wrong family is used for a socket, for example, in sendto." };
	case WSAEADDRINUSE: return{ WSAEADDRINUSE, "WSAEADDRINUSE", "Address already in use", "Typically, only one usage of each socket address (protocol/IP address/port) is permitted. This error occurs if an application attempts to bind a socket to an IP address/port that has already been used for an existing socket, or a socket that was not closed properly, or one that is still in the process of closing. For server applications that need to bind multiple sockets to the same port number, consider using setsockopt (SO_REUSEADDR). Client applications usually need not call bind at all�connect chooses an unused port automatically. When bind is called with a wildcard address (involving ADDR_ANY), a WSAEADDRINUSE error could be delayed until the specific address is committed. This could happen with a call to another function later, including connect, listen, WSAConnect, or WSAJoinLeaf." };
	case WSAEADDRNOTAVAIL: return{ WSAEADDRNOTAVAIL, "WSAEADDRNOTAVAIL", "Cannot assign requested address", "The requested address is not valid in its context. This normally results from an attempt to bind to an address that is not valid for the local computer. This can also result from connect, sendto, WSAConnect, WSAJoinLeaf, or WSASendTo when the remote address or port is not valid for a remote computer (for example, address or port 0)." };
	case WSAENETDOWN: return{ WSAENETDOWN, "WSAENETDOWN", "Network is down", "A socket operation encountered a dead network. This could indicate a serious failure of the network system (that is, the protocol stack that the Windows Sockets DLL runs over), the network interface, or the local network itself." };
	case WSAENETUNREACH: return{ WSAENETUNREACH, "WSAENETUNREACH", "Network is unreachable", "A socket operation was attempted to an unreachable network. This usually means the local software knows no route to reach the remote host." };
	case WSAENETRESET: return{ WSAENETRESET, "WSAENETRESET", "Network dropped connection on reset", "The connection has been broken due to keep-alive activity detecting a failure while the operation was in progress. It can also be returned by setsockopt if an attempt is made to set SO_KEEPALIVE on a connection that has already failed." };
	case WSAECONNABORTED: return{ WSAECONNABORTED, "WSAECONNABORTED", "Software caused connection abort", "An established connection was aborted by the software in your host computer, possibly due to a data transmission time-out or protocol error." };
	case WSAECONNRESET: return{ WSAECONNRESET, "WSAECONNRESET", "Connection reset by peer", "An existing connection was forcibly closed by the remote host. This normally results if the peer application on the remote host is suddenly stopped, the host is rebooted, the host or remote network interface is disabled, or the remote host uses a hard close (see setsockopt for more information on the SO_LINGER option on the remote socket). This error may also result if a connection was broken due to keep-alive activity detecting a failure while one or more operations are in progress. Operations that were in progress fail with WSAENETRESET. Subsequent operations fail with WSAECONNRESET." };
	case WSAENOBUFS: return{ WSAENOBUFS, "WSAENOBUFS", "No buffer space available", "An operation on a socket could not be performed because the system lacked sufficient buffer space or because a queue was full." };
	case WSAEISCONN: return{ WSAEISCONN, "WSAEISCONN", "Socket is already connected", "A connect request was made on an already-connected socket. Some implementations also return this error if sendto is called on a connected SOCK_DGRAM socket (for SOCK_STREAM sockets, the to parameter in sendto is ignored) although other implementations treat this as a legal occurrence." };
	case WSAENOTCONN: return{ WSAENOTCONN, "WSAENOTCONN", "Socket is not connected", "A request to send or receive data was disallowed because the socket is not connected and (when sending on a datagram socket using sendto) no address was supplied. Any other type of operation might also return this error�for example, setsockopt setting SO_KEEPALIVE if the connection has been reset." };
	case WSAESHUTDOWN: return{ WSAESHUTDOWN, "WSAESHUTDOWN", "Cannot send after socket shutdown.", "A request to send or receive data was disallowed because the socket had already been shut down in that direction with a previous shutdown call. By calling shutdown a partial close of a socket is requested, which is a signal that sending or receiving, or both have been discontinued." };
	case WSAETOOMANYREFS: return{ WSAETOOMANYREFS, "WSAETOOMANYREFS", "Too many references", "Too many references to some kernel object." };
	case WSAETIMEDOUT: return{ WSAETIMEDOUT, "WSAETIMEDOUT", "Connection timed out", "A connection attempt failed because the connected party did not properly respond after a period of time, or the established connection failed because the connected host has failed to respond." };
	case WSAECONNREFUSED: return{ WSAECONNREFUSED, "WSAECONNREFUSED", "Connection refused", "No connection could be made because the target computer actively refused it. This usually results from trying to connect to a service that is inactive on the foreign host�that is, one with no server application running." };
	case WSAELOOP: return{ WSAELOOP, "WSAELOOP", "Cannot translate name", "Cannot translate a name" };
	case WSAENAMETOOLONG: return{ WSAENAMETOOLONG, "WSAENAMETOOLONG", "Name too long", "A name component or a name was too long." };
	case WSAEHOSTDOWN: return{ WSAEHOSTDOWN, "WSAEHOSTDOWN", "Host is down", "A socket operation failed because the destination host is down. A socket operation encountered a dead host. Networking activity on the local host has not been initiated. These conditions are more likely to be indicated by the error WSAETIMEDOUT." };
	case WSAEHOSTUNREACH: return{ WSAEHOSTUNREACH, "WSAEHOSTUNREACH", "No route to host", "A socket operation was attempted to an unreachable host. See WSAENETUNREACH." };
	case WSAENOTEMPTY: return{ WSAENOTEMPTY, "WSAENOTEMPTY", "Directory not empty", "Cannot remove a directory that is not empty." };
	case WSAEPROCLIM: return{ WSAEPROCLIM, "WSAEPROCLIM", "Too many processes", "A Windows Sockets implementation may have a limit on the number of applications that can use it simultaneously. WSAStartup may fail with this error if the limit has been reached." };
	case WSAEUSERS: return{ WSAEUSERS, "WSAEUSERS", "User quota exceeded", "Ran out of user quota." };
	case WSAEDQUOT: return{ WSAEDQUOT, "WSAEDQUOT", "Disk quota exceeded", "Ran out of disk quota." };
	case WSAESTALE: return{ WSAESTALE, "WSAESTALE", "Stale file handle reference", "The file handle reference is no longer available." };
	case WSAEREMOTE: return{ WSAEREMOTE, "WSAEREMOTE", "Item is remote", "The item is not available locally." };
	case WSASYSNOTREADY: return{ WSASYSNOTREADY, "WSASYSNOTREADY", "Network subsystem is unavailable", "This error is returned by WSAStartup if the Windows Sockets implementation cannot function at this time because the underlying system it uses to provide network services is currently unavailable. Users should check:\n-That the appropriate Windows Sockets DLL file is in the current path.\n-That they are not trying to use more than one Windows Sockets implementation simultaneously. If there is more than one Winsock DLL on your system, be sure the first one in the path is appropriate for the network subsystem currently loaded.\n-The Windows Sockets implementation documentation to be sure all necessary components are currently installed and configured correctly." };
	case WSAVERNOTSUPPORTED: return{ WSAVERNOTSUPPORTED, "WSAVERNOTSUPPORTED", "Winsock.dll version out of range", "The current Windows Sockets implementation does not support the Windows Sockets specification version requested by the application. Check that no old Windows Sockets DLL files are being accessed." };
	case WSANOTINITIALISED: return{ WSANOTINITIALISED, "WSANOTINITIALISED", "Successful WSAStartup not yet performed.", "Either the application has not called WSAStartup or WSAStartup failed. The application may be accessing a socket that the current active task does not own (that is, trying to share a socket between tasks), or WSACleanup has been called too many times." };
	case WSAEDISCON: return{ WSAEDISCON, "WSAEDISCON", "Graceful shutdown in progress.", "Returned by WSARecv and WSARecvFrom to indicate that the remote party has initiated a graceful shutdown sequence." };
	case WSAENOMORE: return{ WSAENOMORE, "WSAENOMORE", "No more results", "No more results can be returned by the WSALookupServiceNext function." };
	case WSAECANCELLED: return{ WSAECANCELLED, "WSAECANCELLED", "Call has been canceled", "A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled." };
	case WSAEINVALIDPROCTABLE: return{ WSAEINVALIDPROCTABLE, "WSAEINVALIDPROCTABLE", "Procedure call table is invalid", "The service provider procedure call table is invalid. A service provider returned a bogus procedure table to Ws2_32.dll. This is usually caused by one or more of the function pointers being NULL." };
	case WSAEINVALIDPROVIDER: return{ WSAEINVALIDPROVIDER, "WSAEINVALIDPROVIDER", "Service provider is invalid", "The requested service provider is invalid. This error is returned by the WSCGetProviderInfo and WSCGetProviderInfo32 functions if the protocol entry specified could not be found. This error is also returned if the service provider returned a version number other than 2.0." };
	case WSAEPROVIDERFAILEDINIT: return{ WSAEPROVIDERFAILEDINIT, "WSAEPROVIDERFAILEDINIT", "Service provider failed to initialize", "The requested service provider could not be loaded or initialized. This error is returned if either a service provider's DLL could not be loaded (LoadLibrary failed) or the provider's WSPStartup or NSPStartup function failed." };
	case WSASYSCALLFAILURE: return{ WSASYSCALLFAILURE, "WSASYSCALLFAILURE", "System call failure", "A system call that should never fail has failed. This is a generic error code, returned under various conditions.\n\nReturned when a system call that should never fail does fail. For example, if a call to WaitForMultipleEvents fails or one of the registry functions fails trying to manipulate the protocol/namespace catalogs.\n\nReturned when a provider does not return SUCCESS and does not provide an extended error code. Can indicate a service provider implementation error." };
	case WSASERVICE_NOT_FOUND: return{ WSASERVICE_NOT_FOUND, "WSASERVICE_NOT_FOUND", "Service not found", "No such service is known. The service cannot be found in the specified name space." };
	case WSATYPE_NOT_FOUND: return{ WSATYPE_NOT_FOUND, "WSATYPE_NOT_FOUND", "Class type not found", "The specified class was not found." };
	case WSA_E_NO_MORE: return{ WSA_E_NO_MORE, "WSA_E_NO_MORE", "No more results", "No more results can be returned by the WSALookupServiceNext function." };
	case WSA_E_CANCELLED: return{ WSA_E_CANCELLED, "WSA_E_CANCELLED", "Call was canceled", "A call to the WSALookupServiceEnd function was made while this call was still processing. The call has been canceled." };
	case WSAEREFUSED: return{ WSAEREFUSED, "WSAEREFUSED", "Database query was refused", "A database query failed because it was actively refused." };
	default: return{ 0, "UNKNOWN", "Unknown Error", "Error not defined!" };
	}
}