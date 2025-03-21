/*****************************************************************************
 * HInterfaceC.h
 *****************************************************************************
 *
 * Project:      HALCON/HLib
 * Description:  Prototypes for HALCON/C interface
 *
 * (c) 1996-2023 by MVTec Software GmbH
 *                  www.mvtec.com
 *
 *****************************************************************************/

#ifndef HINTERFACE_C_H
#define HINTERFACE_C_H

/*===========================================================================*/
/*                             Defines                                      */
/*===========================================================================*/


/*===========================================================================*/
/*                             Prototypes                                    */
/*===========================================================================*/
extern LIntExport Herror HcErrorHandling(Hproc_handle ph, Herror err);

extern LIntExport Herror HcException(int op_id, Herror err);

extern LIntExport Herror HcPreCall(int proc_index, Hproc_handle* ph);

extern LIntExport Herror HcCall(Hproc_handle ph);

extern LIntExport Herror HcPostCall(Hproc_handle ph, Herror err);

extern LIntExport Herror HcStoreIO(Hproc_handle ph, int par, Hobject inObjVar);

extern LIntExport Herror HcStoreICL(Hproc_handle ph, int par, Hlong value);

extern LIntExport Herror HcStoreICD(Hproc_handle ph, int par, double value);

extern LIntExport Herror HcStoreICS(Hproc_handle ph, int par,
                                    char const* value);
extern LIntExport Herror HcStoreICSEnc(Hproc_handle ph, int par,
                                       char const* value);

extern LIntExport Herror HcStoreICT(Hproc_handle ph, int par,
                                    Htuple const* value);
extern LIntExport Herror HcStoreICTEnc(Hproc_handle ph, int par,
                                       Htuple const* value);


extern LIntExport void HcInitOC(Hproc_handle ph, int par);
extern LIntExport void HcInitOCD(Hproc_handle ph, int par);
extern LIntExport void HcInitOCL(Hproc_handle ph, int par);
extern LIntExport void HcInitOCS(Hproc_handle ph, int par);
extern LIntExport void HcInitOCT(Hproc_handle ph, int par, Hctuple* ctuple);

extern LIntExport Herror HcStoreOO(Hproc_handle ph, int par,
                                   Hobject* outObjVar, Herror err);

extern LIntExport Herror HcStoreOCL(Hproc_handle ph, int par,
                                    Hlong* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCD(Hproc_handle ph, int par,
                                    double* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCS(Hproc_handle ph, int par, char* outCtrlVar,
                                    Herror err);

extern LIntExport Herror HcStoreOCSEnc(Hproc_handle ph, int par,
                                       char* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCT(Hproc_handle ph, int par,
                                    Htuple* outCtrlVar, Herror err);

extern LIntExport Herror HcStoreOCTEnc(Hproc_handle ph, int par,
                                       Htuple* outCtrlVar, Herror err);

#endif
