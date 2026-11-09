# hard coded paths

## traces

    fp=fopen("/usr/people/mat.script","r");
    strcpy(G.ftype,"/usr/people/trace/ftypes/amiga.rgb");
    fp=fopen("/usr/people/normaaldata","r");
    vf= initvfont("/usr/people/trace/font/u/Univers/Univers");
    vf= initvfont("/usr/people/trace/font/g/GillSans/GillSans");
    vf= initvfont("/usr/people/trace/font/f/Futura/Futura");

## chroma

    chroma_main.c
    /data/pics/Chroma_backbuf

## render-gui

    render-gui_cb.c hard coded traces path "/usr/people/bin/traces", set the TRACES_EX environment
    it also support blender at /usr/people/bin/blender
    render-gui_main.c lastfile "/data/"
    also in render.c

## renderd

    renderd.c hard code DAEMONDIR "/daemon" or "/usr/people/daemon"
    render = make_renderfile_old("/usr/people/frank/source/dummy", "/data/rt.blend", "S.first", 1, 100);
    set environment DAEMONDIR, BLENDERDIR

## savedisk.c

    strcpy(trace, "/render/mo/traces/0001");
    strcpy(image, "/render/mo/images/0001");
    strcpy(targa, "/render/mo/targas/0001");
    strcpy(script, "/render/mo/scripts/0001");

## stretch.c

    if (argc ==1) ibuf=loadiffname("/usr/data/pics/rt",LI_rect);

## tocmap.c

    cmap = loadiffname("/hosts/quad/usr/people/blend/cmap.tga", IB_rect);
    ibuf = loadiffname("/hosts/quad/pics/textures/plants1", IB_rect);
    saveiff(ibuf, "/hosts/quad/data/rt", IB_rect | IB_cmap);

## vfrutil.c

    /usr/people/trace/stringtoimage

## wu.c

    ibuf = loadiffname("/data/irisdata/codim/klaar/pano4.tga",LI_rect);
    /data/

## over.c

    /pics/

## /play/play_cb.c

    strcpy(name, "/render/rt.mv");
