TITLE_ID = VITA2DTST
TARGET   = vita_dev_poc
OBJS     = 	src/main.o \
			src/globals.o \
			src/KeyVita.o \
			src/GraphicVita.o \
			src/SceneManager.o \
			src/SceneControler.o \
			src/SplashScreenControler.o \
			src/SplashScreenView.o \
			src/MainMenuControler.o \
			src/SettingsView.o \
			src/SettingsControler.o \
			src/SettingsModel.o \
			src/GameView.o \
			src/GameControler.o \
			src/MainMenuView.o \
			src/ButtonView.o \
			src/ButtonModel.o
			# ressources/image.o
			
PSVITAIP = 192.168.1.14

LIBS = -lvita2d -lSceDisplay_stub -lSceGxm_stub \
	-lSceSysmodule_stub -lSceCtrl_stub -lScePgf_stub -lScePvf_stub \
	-lSceCommonDialog_stub -lfreetype -lpng -ljpeg -lz -lm -lc -lsoloud -lpthread -lm -lSceAudio_stub -lSceDisplay_stub -lSceNet_stub -lSceNetCtl_stub

PREFIX  = arm-vita-eabi
CXX      = $(PREFIX)-g++ -std=gnu++17 -Iinclude -I.
CXXFLAGS  = -DVITA -Wl,-q -Wall -Werror -fno-lto
ASFLAGS = $(CXXFLAGS)

all: $(TARGET).vpk

%.vpk: eboot.bin
	vita-mksfoex -s TITLE_ID=$(TITLE_ID) "$(TARGET)" param.sfo
	vita-pack-vpk -s param.sfo -b eboot.bin $@

eboot.bin: $(TARGET).velf
	vita-make-fself -s $< $@

%.velf: %.elf
	vita-elf-create $< $@

$(TARGET).elf: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ $(LIBS) -o $@

# %.o: %.png
	# $(PREFIX)-ld -r -b binary -o $@ $^

clean:
	@rm -rf $(TARGET).vpk $(TARGET).velf $(TARGET).elf $(OBJS) \
		eboot.bin param.sfo

vpksend: $(TARGET).vpk
	curl -T $(TARGET).vpk ftp://$(PSVITAIP):1337/ux0:/
	@echo "Sent."

send: eboot.bin
	curl -T eboot.bin ftp://$(PSVITAIP):1337/ux0:/app/$(TITLE_ID)/
	@echo "Sent."

re: clean all