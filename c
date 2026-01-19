<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sofía Sandoval Labbé - Portfolio</title>
    <style>
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        body {
            font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', sans-serif;
            background: linear-gradient(135deg, #f5d5e0 0%, #e5d4f5 40%, #f5e8d4 100%);
            min-height: 100vh;
        }

        nav {
            display: flex;
            justify-content: space-between;
            align-items: center;
            padding: 30px 80px;
            border-bottom: 1px solid rgba(0,0,0,0.08);
            position: sticky;
            top: 0;
            background: rgba(255,250,250,0.85);
            backdrop-filter: blur(10px);
            z-index: 100;
        }

        nav ul {
            display: flex;
            gap: 50px;
            list-style: none;
        }

        nav a {
            text-decoration: none;
            color: #000;
            font-weight: 500;
            font-size: 14px;
            letter-spacing: 0.5px;
            transition: opacity 0.3s;
        }

        nav a:hover {
            opacity: 0.6;
        }

        .hero {
            padding: 100px 80px 60px;
        }

        .hero h1 {
            font-size: 120px;
            font-weight: 900;
            line-height: 1;
            margin-bottom: 30px;
            letter-spacing: -2px;
        }

        .hero-subtitle {
            font-size: 24px;
            color: #333;
            margin-bottom: 20px;
            font-weight: 300;
        }

        .hero-description {
            max-width: 800px;
            font-size: 16px;
            line-height: 1.8;
            color: #555;
        }

        .section {
            padding: 80px 80px;
            border-top: 1px solid rgba(0,0,0,0.08);
        }

        .section-title {
            font-size: 32px;
            font-weight: 700;
            margin-bottom: 50px;
            letter-spacing: -0.5px;
        }

        .skills-grid {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 80px;
        }

        .skill-column h3 {
            font-size: 18px;
            font-weight: 700;
            margin-bottom: 30px;
            letter-spacing: 1px;
        }

        .skill-column ul {
            list-style: none;
        }

        .skill-column li {
            font-size: 16px;
            margin-bottom: 15px;
            color: #333;
        }

        .experience-timeline {
            max-width: 900px;
        }

        .experience-item {
            margin-bottom: 50px;
            padding-left: 30px;
            border-left: 2px solid rgba(0,0,0,0.1);
        }

        .experience-item h3 {
            font-size: 22px;
            margin-bottom: 8px;
        }

        .experience-item .role {
            font-size: 16px;
            color: #666;
            margin-bottom: 15px;
            font-style: italic;
        }

        .experience-item .description {
            font-size: 15px;
            line-height: 1.6;
            color: #555;
        }

        .experience-item .year {
            display: inline-block;
            background: #000;
            color: white;
            padding: 4px 12px;
            border-radius: 20px;
            font-size: 12px;
            margin-bottom: 15px;
            font-weight: 600;
        }

        .projects-grid {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 40px;
        }

        .project-card {
            background: white;
            border-radius: 16px;
            overflow: hidden;
            box-shadow: 0 4px 20px rgba(0,0,0,0.08);
            transition: transform 0.3s, box-shadow 0.3s;
            cursor: pointer;
        }

        .project-card:hover {
            transform: translateY(-8px);
            box-shadow: 0 12px 40px rgba(0,0,0,0.12);
        }

        .project-image {
            width: 100%;
            height: 280px;
            display: flex;
            align-items: center;
            justify-content: center;
            font-size: 60px;
        }

        .project-content {
            padding: 25px;
        }

        .project-content h3 {
            font-size: 20px;
            margin-bottom: 10px;
        }

        .project-content p {
            font-size: 14px;
            color: #666;
            line-height: 1.6;
            margin-bottom: 15px;
        }

        .project-tag {
            display: inline-block;
            background: #f0f0f0;
            padding: 5px 12px;
            border-radius: 15px;
            font-size: 12px;
            margin-right: 8px;
            margin-bottom: 8px;
        }

        .project-actions {
            display: flex;
            gap: 10px;
            margin-top: 15px;
        }

        .btn-view, .btn-more {
            padding: 10px 20px;
            border: none;
            border-radius: 6px;
            font-size: 14px;
            font-weight: 600;
            cursor: pointer;
            transition: transform 0.3s, opacity 0.3s;
            text-decoration: none;
            display: inline-block;
            text-align: center;
        }

        .btn-view {
            background: #000;
            color: white;
            flex: 1;
        }

        .btn-view:hover {
            transform: translateY(-2px);
            opacity: 0.9;
        }

        .btn-more {
            background: #f0f0f0;
            color: #000;
            flex: 1;
        }

        .btn-more:hover {
            background: #e0e0e0;
        }

        .modal {
            display: none;
            position: fixed;
            z-index: 1000;
            left: 0;
            top: 0;
            width: 100%;
            height: 100%;
            background: rgba(0,0,0,0.9);
            overflow: auto;
            animation: fadeIn 0.3s;
        }

        .modal.active {
            display: block;
        }

        @keyframes fadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }

        .modal-content {
            position: relative;
            margin: 50px auto;
            max-width: 1200px;
            padding: 20px;
        }

        .modal-close {
            position: fixed;
            top: 30px;
            right: 50px;
            font-size: 40px;
            color: white;
            cursor: pointer;
            background: rgba(0,0,0,0.5);
            width: 50px;
            height: 50px;
            border-radius: 50%;
            display: flex;
            align-items: center;
            justify-content: center;
            z-index: 1001;
            transition: background 0.3s;
        }

        .modal-close:hover {
            background: rgba(0,0,0,0.8);
        }

        .modal-image {
            width: 100%;
            border-radius: 12px;
            margin-bottom: 15px;
            box-shadow: 0 10px 40px rgba(0,0,0,0.5);
        }

        .modal-nav {
            display: flex;
            justify-content: center;
            gap: 20px;
            margin-top: 30px;
        }

        .modal-nav button {
            padding: 12px 30px;
            background: white;
            border: none;
            border-radius: 6px;
            font-size: 16px;
            font-weight: 600;
            cursor: pointer;
            transition: transform 0.3s;
        }

        .modal-nav button:hover {
            transform: translateY(-3px);
        }

        footer {
            padding: 60px 80px;
            display: flex;
            justify-content: space-between;
            align-items: center;
            border-top: 1px solid rgba(0,0,0,0.08);
        }

        .contact-info {
            display: flex;
            flex-direction: column;
            gap: 15px;
        }

        .contact-info h3 {
            font-size: 28px;
            margin-bottom: 10px;
        }

        .contact-info a {
            color: #000;
            text-decoration: none;
            font-size: 16px;
            display: flex;
            align-items: center;
            gap: 10px;
            transition: opacity 0.3s;
        }

        .contact-info a:hover {
            opacity: 0.6;
        }

        .social-links {
            display: flex;
            gap: 15px;
            flex-wrap: wrap;
        }

        .social-links a {
            padding: 12px 20px;
            background: #000;
            color: white;
            text-decoration: none;
            border-radius: 25px;
            font-size: 14px;
            font-weight: 600;
            transition: transform 0.3s, background 0.3s;
        }

        .social-links a:hover {
            transform: translateY(-3px);
            background: #333;
        }

        @media (max-width: 1024px) {
            nav, .hero, .section, footer {
                padding-left: 40px;
                padding-right: 40px;
            }

            .hero h1 {
                font-size: 80px;
            }

            .projects-grid {
                grid-template-columns: 1fr;
            }

            .skills-grid {
                grid-template-columns: 1fr;
                gap: 40px;
            }
        }

        @media (max-width: 768px) {
            nav {
                flex-direction: column;
                gap: 20px;
            }

            nav ul {
                gap: 20px;
                flex-wrap: wrap;
                justify-content: center;
            }

            .hero h1 {
                font-size: 48px;
            }

            .hero-subtitle {
                font-size: 18px;
            }

            footer {
                flex-direction: column;
                gap: 30px;
                text-align: center;
            }

            .social-links {
                justify-content: center;
            }
        }
    </style>
</head>
<body>
    <nav>
        <ul>
            <li><a href="#home">HOME</a></li>
            <li><a href="#experiencia">EXPERIENCIA</a></li>
            <li><a href="#habilidades">HABILIDADES</a></li>
            <li><a href="#proyectos">PROYECTOS</a></li>
        </ul>
        <a href="#contacto">CONTACTO</a>
    </nav>

    <section class="hero" id="home">
        <h1>UI/UX<br>DESIGNER</h1>
        <p class="hero-subtitle">Hola, soy Sofía Sandoval Labbé</p>
        <p class="hero-description">
            Soy diseñadora industrial especializada en diseño UX. En 2025 me titulé con distinción máxima de la Universidad Diego Portales y fui ayudante de un curso de programación. En 2024 hice mi práctica en el Museo Interactivo Mirador (MIM). Manejo herramientas como Figma, Miro y Adobe Illustrator, y cuento con más de dos años de experiencia en el desarrollo de apps y web, además de haber realizado las certificaciones de Google UX en Coursera.
        </p>
    </section>

    <section class="section" id="experiencia">
        <h2 class="section-title">EXPERIENCIA</h2>
        <div class="experience-timeline">
            <div class="experience-item">
                <span class="year">2025</span>
                <h3>Diseño Industrial - Universidad Diego Portales</h3>
                <p class="role">Titulada con distinción máxima</p>
                <p class="description">Top 10% de ranking superior de la generación.</p>
            </div>

            <div class="experience-item">
                <span class="year">2024-2025</span>
                <h3>Ayudante de Cátedra</h3>
                <p class="role">Asignatura Cuerpo, Movimiento y Código - UDP</p>
                <p class="description">Apoyando a estudiantes en la exploración de interfaces interactivas y procesos creativos de tecnología y diseño.</p>
            </div>

            <div class="experience-item">
                <span class="year">2024</span>
                <h3>Práctica Profesional</h3>
                <p class="role">Museo Interactivo Mirador (MIM)</p>
                <p class="description">Creación de app MIM VECINOS para los residentes de la comuna de La Granja.</p>
            </div>

            <div class="experience-item">
                <span class="year">2023-2024</span>
                <h3>Investigadora</h3>
                <p class="role">Universidad Diego Portales</p>
                <p class="description">Creación de template de portafolio para estudiantes de diseño y desarrollo de software para biomateriales.</p>
            </div>

            <div class="experience-item">
                <span class="year">2023</span>
                <h3>Certificación Google UX</h3>
                <p class="role">Coursera</p>
                <p class="description">Certificación profesional en diseño de experiencia de usuario.</p>
            </div>
        </div>
    </section>

    <section class="section" id="habilidades">
        <h2 class="section-title">HABILIDADES</h2>
        <div class="skills-grid">
            <div class="skill-column">
                <h3>HARD SKILLS</h3>
                <ul>
                    <li>FIGMA</li>
                    <li>ADOBE ILLUSTRATOR</li>
                    <li>MIRO</li>
                    <li>HTML - CSS - JS</li>
                    <li>VISUAL STUDIO CODE</li>
                    <li>GITHUB</li>
                    <li>PROTOTYPING</li>
                    <li>USER RESEARCH</li>
                </ul>
            </div>
            <div class="skill-column">
                <h3>SOFT SKILLS</h3>
                <ul>
                    <li>INVESTIGACIÓN APLICADA</li>
                    <li>TRABAJO EN EQUIPO</li>
                    <li>PENSAMIENTO CREATIVO</li>
                    <li>GESTIÓN DE PROYECTOS</li>
                    <li>DISEÑO CENTRADO EN EL USUARIO</li>
                    <li>APRENDIZAJE CONTINUO</li>
                </ul>
            </div>
        </div>
    </section>

    <section class="section" id="proyectos">
        <h2 class="section-title">PROYECTOS</h2>
        <div class="projects-grid">
            <div class="project-card">
                <div class="project-image" style="background: linear-gradient(135deg, #667eea 0%, #764ba2 100%);">
                    💜
                </div>
                <div class="project-content">
                    <h3>Memorias Vivas</h3>
                    <p>Plataforma que integra objetos del recuerdo con un entorno digital, acompañando las distintas fases del duelo a través de ritos simbólicos.</p>
                    <span class="project-tag">Tesis</span>
                    <span class="project-tag">UX/UI</span>
                    <span class="project-tag">IoT</span>
                    <div class="project-actions">
                        <button class="btn-view" onclick="openModal('memorias')">VER PROYECTO</button>
                        <button class="btn-more" onclick="alert('Más información próximamente')">MÁS INFO</button>
                    </div>
                </div>
            </div>

            <div class="project-card">
                <div class="project-image" style="background: linear-gradient(135deg, #f093fb 0%, #f5576c 100%);">
                    🏛️
                </div>
                <div class="project-content">
                    <h3>MIM VECINOS</h3>
                    <p>Aplicación para mejorar la vinculación con vecinos de la Comuna de la Granja y acceso a beneficios del museo.</p>
                    <span class="project-tag">Práctica</span>
                    <span class="project-tag">Mobile App</span>
                    <div class="project-actions">
                        <button class="btn-view" onclick="openModal('mim')">VER PROYECTO</button>
                        <button class="btn-more" onclick="alert('Más información próximamente')">MÁS INFO</button>
                    </div>
                </div>
            </div>

            <div class="project-card">
                <div class="project-image" style="background: linear-gradient(135deg, #4facfe 0%, #00f2fe 100%);">
                    🧬
                </div>
                <div class="project-content">
                    <h3>BioMateria</h3>
                    <p>Software desktop con IA para diseñadores que facilita la investigación aplicada de biomateriales.</p>
                    <span class="project-tag">Investigación</span>
                    <span class="project-tag">GUI</span>
                    <span class="project-tag">IA</span>
                    <div class="project-actions">
                        <button class="btn-view" onclick="openModal('biomateria')">VER PROYECTO</button>
                        <button class="btn-more" onclick="alert('Más información próximamente')">MÁS INFO</button>
                    </div>
                </div>
            </div>

            <div class="project-card">
                <div class="project-image" style="background: linear-gradient(135deg, #43e97b 0%, #38f9d7 100%);">
                    🚌
                </div>
                <div class="project-content">
                    <h3>Pullman del Sur</h3>
                    <p>Aplicación para la venta de boletos de bus con estudio de usuarios y testing de flujos de compra.</p>
                    <span class="project-tag">UX Research</span>
                    <span class="project-tag">Mobile App</span>
                    <div class="project-actions">
                        <button class="btn-view" onclick="openModal('pullman')">VER PROYECTO</button>
                        <button class="btn-more" onclick="alert('Más información próximamente')">MÁS INFO</button>
                    </div>
                </div>
            </div>

            <div class="project-card">
                <div class="project-image" style="background: linear-gradient(135deg, #fa709a 0%, #fee140 100%);">
                    ♻️
                </div>
                <div class="project-content">
                    <h3>ReciOil</h3>
                    <p>App que incentiva el reciclaje de aceite de cocina mediante recompensas, gestionando su recolección para pymes.</p>
                    <span class="project-tag">Sustentabilidad</span>
                    <span class="project-tag">UX/UI</span>
                    <div class="project-actions">
                        <button class="btn-view" onclick="openModal('recioil')">VER PROYECTO</button>
                        <button class="btn-more" onclick="alert('Más información próximamente')">MÁS INFO</button>
                    </div>
                </div>
            </div>

            <div class="project-card">
                <div class="project-image" style="background: linear-gradient(135deg, #30cfd0 0%, #330867 100%);">
                    🎲
                </div>
                <div class="project-content">
                    <h3>TRYO</h3>
                    <p>Juego físico de ingenio en cubo de madera de roble, diseñado y fabricado 100% a mano.</p>
                    <span class="project-tag">Diseño Industrial</span>
                    <span class="project-tag">Artesanía</span>
                    <div class="project-actions">
                        <button class="btn-view" onclick="openModal('tryo')">VER PROYECTO</button>
                        <button class="btn-more" onclick="alert('Más información próximamente')">MÁS INFO</button>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <!-- Modals para cada proyecto -->
    <div id="modal-memorias" class="modal">
        <div class="modal-close" onclick="closeModal('memorias')">&times;</div>
        <div class="modal-content">
            <img src="https://via.placeholder.com/1200x800/667eea/ffffff?text=Memorias+Vivas+-+Imagen+1" class="modal-image" alt="Memorias Vivas">
            <img src="https://via.placeholder.com/1200x800/764ba2/ffffff?text=Memorias+Vivas+-+Imagen+2" class="modal-image" alt="Memorias Vivas">
            <img src="https://via.placeholder.com/1200x800/667eea/ffffff?text=Eternal+Lamp" class="modal-image" alt="Eternal Lamp">
            <img src="https://via.placeholder.com/1200x800/764ba2/ffffff?text=Recordis+Joya" class="modal-image" alt="Recordis Joya">
            <img src="https://via.placeholder.com/1200x800/667eea/ffffff?text=Aura+Frame" class="modal-image" alt="Aura Frame">
            <div class="modal-nav">
                <button onclick="closeModal('memorias')">CERRAR</button>
            </div>
        </div>
    </div>

    <div id="modal-mim" class="modal">
        <div class="modal-close" onclick="closeModal('mim')">&times;</div>
        <div class="modal-content">
            <img src="https://via.placeholder.com/1200x800/f093fb/ffffff?text=MIM+VECINOS+-+Pantalla+1" class="modal-image" alt="MIM VECINOS">
            <img src="https://via.placeholder.com/1200x800/f5576c/ffffff?text=MIM+VECINOS+-+Pantalla+2" class="modal-image" alt="MIM VECINOS">
            <img src="https://via.placeholder.com/1200x800/f093fb/ffffff?text=MIM+VECINOS+-+Pantalla+3" class="modal-image" alt="MIM VECINOS">
            <div class="modal-nav">
                <button onclick="closeModal('mim')">CERRAR</button>
            </div>
        </div>
    </div>

    <div id="modal-biomateria" class="modal">
        <div class="modal-close" onclick="closeModal('biomateria')">&times;</div>
        <div class="modal-content">
            <img src="https://via.placeholder.com/1200x800/4facfe/ffffff?text=BioMateria+-+Interface" class="modal-image" alt="BioMateria">
            <img src="https://via.placeholder.com/1200x800/00f2fe/ffffff?text=BioMateria+-+Dashboard" class="modal-image" alt="BioMateria">
            <div class="modal-nav">
                <button onclick="closeModal('biomateria')">CERRAR</button>
            </div>
        </div>
    </div>

    <div id="modal-pullman" class="modal">
        <div class="modal-close" onclick="closeModal('pullman')">&times;</div>
        <div class="modal-content">
            <img src="https://via.placeholder.com/1200x800/43e97b/ffffff?text=Pullman+del+Sur+-+App" class="modal-image" alt="Pullman del Sur">
            <img src="https://via.placeholder.com/1200x800/38f9d7/ffffff?text=Pullman+del+Sur+-+Flujos" class="modal-image" alt="Pullman del Sur">
            <div class="modal-nav">
                <button onclick="closeModal('pullman')">CERRAR</button>
            </div>
        </div>
    </div>

    <div id="modal-recioil" class="modal">
        <div class="modal-close" onclick="closeModal('recioil')">&times;</div>
        <div class="modal-content">
            <img src="https://via.placeholder.com/1200x800/fa709a/ffffff?text=ReciOil+-+Screens" class="modal-image" alt="ReciOil">
            <img src="https://via.placeholder.com/1200x800/fee140/ffffff?text=ReciOil+-+Features" class="modal-image" alt="ReciOil">
            <div class="modal-nav">
                <button onclick="closeModal('recioil')">CERRAR</button>
            </div>
        </div>
    </div>

    <div id="modal-tryo" class="modal">
        <div class="modal-close" onclick="closeModal('tryo')">&times;</div>
        <div class="modal-content">
            <img src="https://via.placeholder.com/1200x800/30cfd0/ffffff?text=TRYO+-+Juego" class="modal-image" alt="TRYO">
            <img src="https://via.placeholder.com/1200x800/330867/ffffff?text=TRYO+-+Detalles" class="modal-image" alt="TRYO">
            <div class="modal-nav">
                <button onclick="closeModal('tryo')">CERRAR</button>
            </div>
        </div>
    </div>

    <section class="section" id="contacto" style="background: rgba(255,255,255,0.3);">
        <h2 class="section-title">¿COLABORAMOS?</h2>
        <div style="max-width: 700px; margin: 0 auto;">
            <form id="contactForm" style="display: flex; flex-direction: column; gap: 20px;">
                <div style="display: grid; grid-template-columns: 1fr 1fr; gap: 20px;">
                    <input 
                        type="text" 
                        name="nombre" 
                        placeholder="Nombre" 
                        required
                        style="padding: 15px 20px; border: 1px solid rgba(0,0,0,0.1); border-radius: 8px; font-size: 16px; font-family: inherit; background: white;">
                    
                    <input 
                        type="email" 
                        name="email" 
                        placeholder="Email" 
                        required
                        style="padding: 15px 20px; border: 1px solid rgba(0,0,0,0.1); border-radius: 8px; font-size: 16px; font-family: inherit; background: white;">
                </div>
                
                <input 
                    type="text" 
                    name="asunto" 
                    placeholder="Asunto" 
                    required
                    style="padding: 15px 20px; border: 1px solid rgba(0,0,0,0.1); border-radius: 8px; font-size: 16px; font-family: inherit; background: white;">
                
                <textarea 
                    name="mensaje" 
                    placeholder="Mensaje" 
                    rows="6" 
                    required
                    style="padding: 15px 20px; border: 1px solid rgba(0,0,0,0.1); border-radius: 8px; font-size: 16px; font-family: inherit; resize: vertical; background: white;"></textarea>
                
                <button 
                    type="submit"
                    style="padding: 15px 40px; background: #000; color: white; border: none; border-radius: 8px; font-size: 16px; font-weight: 600; cursor: pointer; transition: transform 0.3s, background 0.3s;">
                    ENVIAR MENSAJE
                </button>
            </form>
            
            <div style="margin-top: 40px; text-align: center; padding-top: 40px; border-top: 1px solid rgba(0,0,0,0.08);">
                <p style="margin-bottom: 15px; color: #666;">O contáctame directamente:</p>
                <a href="mailto:ssofia.sandoval.labbe@gmail.com" style="color: #000; text-decoration: none; font-size: 16px; font-weight: 500;">✉️ ssofia.sandoval.labbe@gmail.com</a>
            </div>
        </div>
    </section>

    <footer>
        <div style="text-align: center; width: 100%;">
            <div class="social-links" style="justify-content: center; margin-bottom: 20px;">
                <a href="https://www.linkedin.com/in/sofia-sandoval" target="_blank">LINKEDIN</a>
                <a href="https://www.instagram.com/tu_usuario" target="_blank">INSTAGRAM</a>
                <a href="https://github.com/tu_usuario" target="_blank">GITHUB</a>
            </div>
            <p style="color: #666; font-size: 14px;">© 2026 Sofía Sandoval Labbé. Todos los derechos reservados.</p>
        </div>
    </footer>

    <script>
        // Funciones para abrir y cerrar modales
        function openModal(projectId) {
            document.getElementById('modal-' + projectId).classList.add('active');
            document.body.style.overflow = 'hidden';
        }

        function closeModal(projectId) {
            document.getElementById('modal-' + projectId).classList.remove('active');
            document.body.style.overflow = 'auto';
        }

        // Cerrar modal al hacer clic fuera de la imagen
        document.querySelectorAll('.modal').forEach(modal => {
            modal.addEventListener('click', function(e) {
                if (e.target === this) {
                    this.classList.remove('active');
                    document.body.style.overflow = 'auto';
                }
            });
        });

        // Cerrar modal con tecla ESC
        document.addEventListener('keydown', function(e) {
            if (e.key === 'Escape') {
                document.querySelectorAll('.modal.active').forEach(modal => {
                    modal.classList.remove('active');
                    document.body.style.overflow = 'auto';
                });
            }
        });

        // Formulario de contacto
        document.getElementById('contactForm').addEventListener('submit', function(e) {
            e.preventDefault();
            
            const nombre = this.nombre.value;
            const email = this.email.value;
            const asunto = this.asunto.value;
            const mensaje = this.mensaje.value;
            
            const mailtoLink = `mailto:ssofia.sandoval.labbe@gmail.com?subject=${encodeURIComponent(asunto)}&body=${encodeURIComponent(
                `Nombre: ${nombre}\nEmail: ${email}\n\nMensaje:\n${mensaje}`
            )}`;
            
            window.location.href = mailtoLink;
            
            this.reset();
            alert('¡Gracias por tu mensaje! Se abrirá tu cliente de correo.');
        });

        document.querySelector('button[type="submit"]').addEventListener('mouseenter', function() {
            this.style.transform = 'translateY(-3px)';
            this.style.background = '#333';
        });

        document.querySelector('button[type="submit"]').addEventListener('mouseleave', function() {
            this.style.transform = 'translateY(0)';
            this.style.background = '#000';
        });
    </script>
</body>
</html>
