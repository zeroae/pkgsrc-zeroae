#!/sbin/sh
# Copyright 2006 Sun Microsystems, Inc. All rights reserved.
# Use is subject to license terms.
#
# ident "%Z%%M% %I% %E SMI"
. /lib/svc/share/smf_include.sh

# SMF_FMRI is the name of the target service. This allows multiple instances
# to use the same script.

getproparg()
{     val=`svcprop -p $1 $SMF_FMRI`
      [ -n "$val" ] && echo $val
}

PGBIN=@PREFIX@/bin
PGTYPE=`getproparg config/type`
PGDATA=`getproparg config/data`
PGLOG=`getproparg config/log`

if [ -z $SMF_FMRI ]; then
     echo "SMF framework variables are not initialized."
     exit $SMF_EXIT_ERR
fi

if [ -z PGTYPE ]; then

     echo "postgresql/type property not set"
     exit $SMF_EXIT_ERR_CONFIG
fi

if [ -z $PGDATA ]; then

     echo "postgresql/data property not set"
     exit $SMF_EXIT_ERR_CONFIG
fi

if [ -z $PGLOG ]; then

     echo "postgresql/log property not set"
     exit $SMF_EXIT_ERR_CONFIG
fi

case "$1" in
'start')
     ulimit -n 10240
     $PGBIN/gtm_ctl -Z $PGTYPE -D $PGDATA -l $PGLOG start
     ;;

'stop')
     $PGBIN/gtm_ctl -Z $PGTYPE -D $PGDATA stop
     ;;

'refresh')
     $PGBIN/gtm_ctl -Z $PGTYPE -D $PGDATA reload
     ;;
*)

     echo $"Usage: $0 {start|stop|refresh}"
     exit 1
     ;;

esac
exit $SMF_EXIT_OK
