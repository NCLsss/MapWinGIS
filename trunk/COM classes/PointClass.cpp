/**************************************************************************************
 * File name: PointClass.cpp 
 *
 * Project: MapWindow Open Source (MapWinGis ActiveX control) 
 * Description: Implementation of CPointClass
 *
 **************************************************************************************
 * The contents of this file are subject to the Mozilla Public License Version 1.1
 * (the "License"); you may not use this file except in compliance with 
 * the License. You may obtain a copy of the License at http://www.mozilla.org/mpl/ 
 * See the License for the specific language governing rights and limitations
 * under the License.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 ************************************************************************************** 
 * Contributor(s): 
 * (Open source contributors should list themselves and their modifications here). */
 
#include "stdafx.h"
#include "PointClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// CPointClass
STDMETHODIMP CPointClass::get_X(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	*pVal = _x;

	return S_OK;
}

STDMETHODIMP CPointClass::put_X(double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	_x = newVal;

	return S_OK;
}

STDMETHODIMP CPointClass::get_Y(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	*pVal = _y;

	return S_OK;
}

STDMETHODIMP CPointClass::put_Y(double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	_y = newVal;

	return S_OK;
}

STDMETHODIMP CPointClass::get_Z(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	*pVal = _z;

	return S_OK;
}

STDMETHODIMP CPointClass::put_Z(double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	_z = newVal;

	return S_OK;
}

STDMETHODIMP CPointClass::get_LastErrorCode(long *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	*pVal = _lastErrorCode;
	_lastErrorCode = tkNO_ERROR;

	return S_OK;
}

STDMETHODIMP CPointClass::get_ErrorMsg(long ErrorCode, BSTR *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	USES_CONVERSION;
	*pVal = A2BSTR(ErrorMsg(ErrorCode));

	return S_OK;
}

STDMETHODIMP CPointClass::get_GlobalCallback(ICallback **pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	*pVal = _globalCallback;
	if( _globalCallback != NULL )
		_globalCallback->AddRef();
	return S_OK;
}

STDMETHODIMP CPointClass::put_GlobalCallback(ICallback *newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	Utility::put_ComReference(newVal, (IDispatch**)&_globalCallback);
	return S_OK;
}

STDMETHODIMP CPointClass::get_Key(BSTR *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	USES_CONVERSION;
	*pVal = OLE2BSTR(_key);
	return S_OK;
}

STDMETHODIMP CPointClass::put_Key(BSTR newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	
	::SysFreeString(_key);
	_key = OLE2BSTR(newVal);

	return S_OK;
}

STDMETHODIMP CPointClass::get_M(double *pVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	*pVal = _m;

	return S_OK;
}

STDMETHODIMP CPointClass::put_M(double newVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())

	_m = newVal;

	return S_OK;
}

// ************************************************************
//		Clone()
// ************************************************************
STDMETHODIMP CPointClass::Clone(IPoint** retVal)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState())
	CoCreateInstance( CLSID_Point, NULL, CLSCTX_INPROC_SERVER, IID_IPoint, (void**)retVal );
	(*retVal)->put_X(_x);
	(*retVal)->put_Y(_y);
	(*retVal)->put_Z(_z);
	(*retVal)->put_M(_m);
	
	if (_globalCallback != NULL)	(*retVal)->put_GlobalCallback(_globalCallback);
	return S_OK;
}
