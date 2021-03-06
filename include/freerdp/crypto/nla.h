/**
 * FreeRDP: A Remote Desktop Protocol Implementation
 * Credential Security Support Provider (CredSSP)
 *
 * Copyright 2010-2012 Marc-Andre Moreau <marcandre.moreau@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FREERDP_SSPI_CREDSSP_H
#define FREERDP_SSPI_CREDSSP_H

typedef struct rdp_credssp rdpCredssp;

#include <freerdp/api.h>
#include <freerdp/freerdp.h>
#include <freerdp/utils/stream.h>

#include <winpr/sspi.h>

#include <freerdp/crypto/tls.h>
#include <freerdp/crypto/ber.h>
#include <freerdp/crypto/der.h>
#include <freerdp/crypto/crypto.h>

struct rdp_credssp
{
	rdpTls* tls;
	BOOL server;
	int send_seq_num;
	int recv_seq_num;
	freerdp* instance;
	CtxtHandle context;
	LPTSTR SspiModule;
	rdpSettings* settings;
	SecBuffer negoToken;
	SecBuffer pubKeyAuth;
	SecBuffer authInfo;
	SecBuffer PublicKey;
	SecBuffer ts_credentials;
	CryptoRc4 rc4_seal_state;
	LPTSTR ServicePrincipalName;
	SEC_WINNT_AUTH_IDENTITY identity;
	PSecurityFunctionTable table;
	SecPkgContext_Sizes ContextSizes;
};

FREERDP_API int credssp_authenticate(rdpCredssp* credssp);

FREERDP_API rdpCredssp* credssp_new(freerdp* instance, rdpTls* tls, rdpSettings* settings);
FREERDP_API void credssp_free(rdpCredssp* credssp);

#endif /* FREERDP_SSPI_CREDSSP_H */
