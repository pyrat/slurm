/*****************************************************************************\
 *  slurm_jobacct_storage.h - Define storage plugin functions.
 *
 * $Id: slurm_jobacct_storage.h 10574 2006-12-15 23:38:29Z jette $
 *****************************************************************************
 *  Copyright (C) 2004-2006 The Regents of the University of California.
 *  Produced at Lawrence Livermore National Laboratory (cf, DISCLAIMER).
 *  Written by Danny Auble <da@llnl.gov>
 *  UCRL-CODE-226842.
 *  
 *  This file is part of SLURM, a resource management program.
 *  For details, see <http://www.llnl.gov/linux/slurm/>.
 *  
 *  SLURM is free software; you can redistribute it and/or modify it under
 *  the terms of the GNU General Public License as published by the Free
 *  Software Foundation; either version 2 of the License, or (at your option)
 *  any later version.
 *
 *  In addition, as a special exception, the copyright holders give permission 
 *  to link the code of portions of this program with the OpenSSL library under
 *  certain conditions as described in each individual source file, and 
 *  distribute linked combinations including the two. You must obey the GNU 
 *  General Public License in all respects for all of the code used other than 
 *  OpenSSL. If you modify file(s) with this exception, you may extend this 
 *  exception to your version of the file(s), but you are not obligated to do 
 *  so. If you do not wish to do so, delete this exception statement from your
 *  version.  If you delete this exception statement from all source files in 
 *  the program, then also delete it here.
 *  
 *  SLURM is distributed in the hope that it will be useful, but WITHOUT ANY
 *  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 *  FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 *  details.
 *  
 *  You should have received a copy of the GNU General Public License along
 *  with SLURM; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
\*****************************************************************************/

#ifndef _SLURM_JOBACCT_STORAGE_H 
#define _SLURM_JOBACCT_STORAGE_H

#include "src/common/list.h"
#include "src/slurmctld/slurmctld.h"
#include <slurm/slurm.h>
#include <slurm/slurm_errno.h>

extern int slurm_jobacct_storage_init(void); /* load the plugin */
extern int slurm_jobacct_storage_fini(void); /* unload the plugin */
/* 
 * Initialize the storage make sure tables are created and in working
 * order
 */
extern int jobacct_storage_g_init (char *location);

/*
 * finish up storage connection
 */
extern int jobacct_storage_g_fini ();

/* 
 * load into the storage the start of a job
 */
extern int jobacct_storage_g_job_start (struct job_record *job_ptr);

/* 
 * load into the storage the end of a job
 */
extern int jobacct_storage_g_job_complete (struct job_record *job_ptr);

/* 
 * load into the storage the start of a job step
 */
extern int jobacct_storage_g_step_start (struct step_record *step_ptr);

/* 
 * load into the storage the end of a job step
 */
extern int jobacct_storage_g_step_complete (struct step_record *step_ptr);

/* 
 * load into the storage a suspention of a job
 */
extern int jobacct_storage_g_job_suspend (struct job_record *job_ptr);

/* 
 * get info from the storage 
 * in/out job_list List of job_rec_t *
 * note List needs to be freed when called
 */
extern void jobacct_storage_g_get_jobs(List job_list,
				       List selected_steps,
				       List selected_parts,
				       void *params);

/* 
 * expire old info from the storage 
 */
extern void jobacct_storage_g_archive(List selected_parts, void *params);




#endif /*_SLURM_JOBACCT_STORAGE_H*/
